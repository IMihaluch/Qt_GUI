#include "editortexts.h"

EditorTexts::EditorTexts(QWidget *parent) : QMainWindow(parent)
{
    tab_A = new QTabWidget(this);
    tab_A->setMovable(true);

    tab_A->setTabsClosable(true);
    tab_A->setUsesScrollButtons(true);

    m_Exit = new QMessageBox(this);
    Ok = new QPushButton(this);
    m_Exit->addButton(Ok, QMessageBox::YesRole);
    Cancel = new QPushButton(this);
    m_Exit->addButton(Cancel, QMessageBox::NoRole);

    m_TabClose = new QMessageBox(this);
    Ok_Close = new QPushButton(this);
    Cancel_Close = new QPushButton(this);
    m_TabClose->addButton(Ok_Close, QMessageBox::YesRole);
    m_TabClose->addButton(Cancel_Close, QMessageBox::NoRole);

    mainGrid = new QGridLayout(this);
    centralWgt = new QWidget(this);
    openread_A = new QAction(this);
    action_Open = new QAction(this);

    but_Open = new QToolButton(this);
    
    but_Open->setIcon(QIcon(":/Icons/open.png"));
    but_Open->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    but_Open->setPopupMode(QToolButton::MenuButtonPopup);
    but_Open->addAction(action_Open);
    but_Open->addAction(openread_A);
    but_Open->setFixedSize(40, 30);
   
    but_Save = new QPushButton(this);
    but_Save->setIcon(QIcon(":/Icons/save.png"));
    but_Save->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    but_Settings = new QPushButton(this);
    but_Settings->setIcon(QIcon(":/Icons/setings.png"));
    but_Settings->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
   
    but_Help = new QPushButton(this);
    but_Help->setIcon(QIcon(":/Icons/help.png"));
    but_Help->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    but_Print = new QPushButton(this);
    but_Print->setIcon(QIcon(":/Icons/print.png"));
    but_Print->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
     
    mainGrid->addWidget(but_Open, 0, 0);
    mainGrid->addWidget(but_Save, 0, 1);
    mainGrid->addWidget(but_Print, 0, 2);
    mainGrid->addWidget(but_Settings, 0, 4);
    mainGrid->addWidget(but_Help, 0, 5);
    mainGrid->addWidget(tab_A, 1, 0, 1, 6);
    setting = new Settings(this);
    setting->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    modOpen = setting->getHotkey()[0];
    open = static_cast<int>(setting->getHotkey()[1]);
    modSave = setting->getHotkey()[2];
    save = static_cast<int>(setting->getHotkey()[3]);
    modClear = setting->getHotkey()[4];
    clear = static_cast<int>(setting->getHotkey()[5]);
    modExit = setting->getHotkey()[6];
    exit = static_cast<int>(setting->getHotkey()[7]);

    centralWgt->setLayout(mainGrid);
    this->setCentralWidget(centralWgt);

    M_bar = new QMenuBar(this);

    file_M = new QMenu(M_bar);
    edit_M = new QMenu(M_bar);
    help_M = new QMenu(M_bar);  

    action_Create = new QAction(this);
    action_Create->setIcon(QIcon(":/Icons/main.png"));

    action_Open->setIcon(QIcon(":/Icons/open.png"));
    action_Save = new QAction(this);
    action_Save->setIcon(QIcon(":/Icons/save.png"));
    action_Print = new QAction(this);
    action_Print->setIcon(QIcon(":/Icons/print.png"));
    action_Exit = new QAction(this);
    action_Exit->setIcon(QIcon(":/Icons/cancel.png"));
    action_Setings = new QAction(this);
    action_Setings->setIcon(QIcon(":/Icons/setings.png"));
    action_Help = new QAction(this);
    action_Help->setIcon(QIcon(":/Icons/help.png"));

    M_bar->addAction(file_M->M_Action());
    M_bar->addAction(edit_M->M_Action());
    M_bar->addAction(help_M->M_Action());

    file_M->addAction(action_Create);
    file_M->addAction(action_Open);
    file_M->addAction(action_Save);
    file_M->addAction(action_Print);
    file_M->addSeparator();
    file_M->addAction(action_Exit);
    edit_M->addAction(action_Setings);
    help_M->addAction(action_Help);

    this->setMenuBar(M_bar);


    connect(but_Open, SIGNAL(clicked()), this, SLOT(on_but_Open_clicked()));
    connect(but_Save, SIGNAL(clicked()), this, SLOT(on_but_Save_clicked()));
    connect(but_Print, SIGNAL(clicked()), this, SLOT(on_action_Print_clicked()));
    connect(but_Help, SIGNAL(clicked()), this, SLOT(on_but_Help_clicked()));
    connect(openread_A, SIGNAL(triggered()), this, SLOT(on_but_OpenOnlyRead_clicked()));
    connect(but_Settings, SIGNAL(clicked()), this, SLOT(on_but_Settings_clicked()));
    connect(setting, SIGNAL(retranslate()), this, SLOT(retranslateUI()));
    connect(setting, SIGNAL(redraw(QString, QPalette)), this, SLOT(redrawUI(QString, QPalette)));
    connect(setting, SIGNAL(com_changeOpen(unsigned int, int)), this, SLOT(switch_HKeyOpen(unsigned int, int)));
    connect(setting, SIGNAL(com_changeSave(unsigned int, int)), this, SLOT(switch_HKeySave(unsigned int, int)));
    connect(setting, SIGNAL(com_changeClear(unsigned int, int)), this, SLOT(switch_HKeyClear(unsigned int, int)));
    connect(setting, SIGNAL(com_changeExit(unsigned int, int)), this, SLOT(switch_HKeyExit(unsigned int, int)));

    connect(action_Create, SIGNAL(triggered(bool)), this, SLOT(on_but_CreateNew_clicked()));
    connect(action_Open, SIGNAL(triggered(bool)), this, SLOT(on_but_Open_clicked()));
    connect(action_Save, SIGNAL(triggered(bool)), this, SLOT(on_but_Save_clicked()));
    connect(action_Print, SIGNAL(triggered(bool)), this, SLOT(on_action_Print_clicked()));
    connect(action_Exit, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(action_Setings, SIGNAL(triggered(bool)), this, SLOT(on_but_Settings_clicked()));
    connect(action_Help, SIGNAL(triggered(bool)), this, SLOT(on_but_Help_clicked()));
    connect(tab_A, SIGNAL(currentChanged(int)), this, SLOT(changeTab_A())); //вкладка
    connect(tab_A, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab_A(int)));

    retranslateUI();
    redrawUI(setting->getQss(), setting->getPalette());
}

void TextEditor::closeEvent(QCloseEvent *event)
{
        event->ignore();

        m_Exit->setIcon(QMessageBox::Information);
        m_Exit->exec();

        if (m_Exit->clickedButton() == yes) {
            while(tab_A->count() != 0){
                closeTab_A(tab_A->currentIndex());
            }
            event->accept();
        }

void EditorTexts::keyPressEvent(QKeyEvent *event)
{
    if( (event->mods() == modOpen && event->key() == open) ||
            (modOpen == 0 && event->key() == open)){
        on_but_Open_clicked();
    }
    else if ( ((event->mods() ==  modSave) && event->key() == save) ||
               (modSave == 0 && event->key() == save)){
        on_but_Save_clicked();
    }
    else if ( ((event->mods() ==  modClear) && event->key() == clear) ||
                (modClear == 0 && event->key() == clear)){
        on_but_CreateNew_clicked();
    }
    else if ( ((event->mods() == modExit) && event->key() == exit) ||
                (modExit == 0 && event->key() == exit)){
        qApp->exit();
    }

void EditorTexts::on_but_Open_clicked()

QPlainTextEdit *textEdit = new QPlainTextEdit(this);
    textEdit->setReadOnly(setOnlyReadText);
    textEdit->setPlainText("");
    connect(textEdit, SIGNAL(textChanged()), this, SLOT(planeTxtChange()));

    {
    QString fileName;
       fileName = QFileDialog::getOpenFileName(this,
                tr("Open file"), QDir::currentPath(), "Files (*.* ALL)");
       if (fileName.isEmpty())  
 return;

    QFile file(fileName);
    QByteArray data; 
    if (!file.open(QIODevice::ReadOnly)) 
        return;
    data = file.readAll(); 
    QFileInfo fileInfo(fileName);
    int newTab = tab_A->addTab(textEdit, fileInfo.fileName());
    tab_A->setTabToolTip(newTab, fileName);
    tab_A->setCurrentIndex(newTab);
    textEdit->setPlainText(data);
    tab_A->setTabText(newTab, tab_A->tabText(newTab).remove(0,1));
    setOnlyReadText = false;
}

void EditorTexts::on_but_Save_clicked()
{
    QString fileName;
        try	{
            fileName = QFileDialog::getSaveFileName(this,
                tr("Save file"), QDir::currentPath(), "Files (*.txt)");
        }
        catch (const std::exception&)
{
                fileName = "";
        }

        if (!fileName.isEmpty())
{
            QFile file(fileName);
            if (!file.open(QFile::WriteOnly)) 
            return;
            QTextStream stream(&file);
            QWidget *widg = tab_A->currentWidget();
            if(widg) {
                QPlainTextEdit *EditorText = static_cast<QPlainTextEdit*>(widg);
                stream << EditorText->toPlainText();
                QFileInfo fileInfo(fileName);
                tab_A->setTabToolTip(tab_A->currentIndex(), fileName);
                tab_A->setTabText(tab_A->currentIndex(), fileInfo.fileName());
            }
            file.close();
        }
}

void EditorTexts::on_but_Help_clicked()
{
    QFile file(":/Txt/readme.txt");
    if(!file.open(QIODevice::ReadOnly)) return;
    QString info = file.readAll();
    QMessageBox::information(nullptr, tr("Help"), info);
}
void EditorTexts::on_buttonSettings_clicked()
{
    setting->show();
}

void EditorTexts::on_buttonOpenOnlyRead_clicked()
{
    setOnlyReadText = true;
    on_buttonOpen_clicked();
    }

void TextEditor::on_buttonCreateNew_clicked()
{
    QPlainTextEdit *textEdit = new QPlainTextEdit(this);
    textEdit->setReadOnly(setOnlyReadText);
    textEdit->setPlainText("");
    textEdit->setToolTip("");
    int newTab = tab_A->addTab(textEdit, "*unknown");
    tab_A->setCurrentIndex(newTab);
    QObject::connect(textEdit, SIGNAL(textChanged()), this, SLOT(planeTxtChange()));
}

void EditorTexts::retranslateUI()
{
    this->setWindowTitle(tr("Text editor"));
    openA->setText(tr("Open"));
    openreadA->setText(tr("Open Read only"));
    but_Open->setToolTip(tr("Open"));
    but_Save->setToolTip(tr("Save"));
    but_Help->setToolTip(tr("Help"));
    but_Settings->setToolTip(tr("Settings"));
    but_Print->setToolTip(tr("Print"));

    file_M->setTitle(tr("File"));
    edit_M->setTitle(tr("Edit"));
    help_M->setTitle(tr("Help"));

    action_Create->setText(tr("Create"));
    action_Open->setText(tr("Open"));
    action_Save->setText(tr("Save"));
    action_Print->setText(tr("Print"));
    action_Exit->setText(tr("Exit"));
    action_Setings->setText(tr("Setings"));
    action_Help->setText(tr("About"));

    m_Exit->setWindowTitle(tr("Exit"));
    m_Exit->setText(tr("To exit the programm?"));
    m_TabClose->setWindowTitle(tr("Close tab"));
    m_TabClose->setText(tr("Save changes?"));
    Ok->setText(tr("Ok"));
    Cancel->setText(tr("Cancel"));
    Ok_Close->setText(tr("Ok"));
    Cancel_Close->setText(tr("Cancel"));

    setting->retranslateUI();
    }

void EditorTexts::redrawUI(QString _qss, QPalette _palette)
{
    this->setPalette(_palette);
    but_Open->setStyleSheet(_qss);
    but_Save->setStyleSheet(_qss);
    but_Print->setStyleSheet(_qss);
    but_Help->setStyleSheet(_qss);
    but_Settings->setStyleSheet(_qss);

    centralWgt->setStyleSheet(_qss);
    setting->redrawUI(_qss, _palette);
}

void EditorTexts::switch_HKeyOpen(unsigned int _mod, int _key)
{
    open = _key; modOpen = _mod;
}

void EditorTexts::switch_HKeySave(unsigned int _mod, int _key)
{
    save = _key; modSave = _mod;
}

void EditorTexts::switch_HKeyClear(unsigned int _mod, int _key)
{
    clear = _key; modClear = _mod;
}

void EditorTexts::switch_HKeyExit(unsigned int _mod, int _key)
{
    exit = _key; modExit = _mod;

}

void EditorTexts::on_action_Print_clicked()
{
   QPrinter printer;
   QPrintDialog dlg(&printer, this);
   dlg.setWindowTitle("Print");
   if (dlg.exec() != QDialog::Accepted)
       return;
   QWidget *widg = tab_A->currentWidget();
   QPlainTextEdit *EditorTexts = static_cast<QPlainTextEdit*>(widg);
   EditorTexts->print(&printer);
}

void EditorTexts::changeTab_A()
{
    QWidget *widg = tab_A->currentWidget();
    if(widg) {
        QPlainTextEdit *EditorTexts = static_cast<QPlainTextEdit*>(widg);
        find->setTextEdit(EditorText);
    }
}

void EditorTexts::closeTab_A(int _tab)
{
    if(tab_A->tabText(_tab)[0] == '*') {
        m_TabClose->setIcon(QMessageBox::Information);
        m_TabClose->exec();
        if (m_TabClose->clickedButton() == Ok_Close){
            on_buttonSave_clicked(); 
        }
    }
    tab_A->removeTab(_tab);
}

void EditorTexsts::planeTxtChange()
{
    if(tab_A->tabText(tab_A->currentIndex())[0] != '*')
        tab_A->setTabText(tab_A->currentIndex(), tab_A->tabText(tab_A->currentIndex()).insert(0, '*'));
}
