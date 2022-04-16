#include "editortexts.h"

EditorTexts::EditorTexts(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);
    openA = new QAction(this);
    openreadA = new QAction(this);

    but_Open = new QToolButton(this);
    but_Open->setIcon(QIcon(":/Icons/open.png"));
    but_Open->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    but_Open->setPopupMode(QToolButton::MenuButtonPopup);
    but_Open->addAction(openAct);
    but_Open->addAction(openReadAct);
    but_Open->setFixedSize(40, 30);
   
    but_Save = new QPushButton(this);
    but_Save->setIcon(QIcon(":/Icons/save.png"));
    but_Save->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
   
    but_Help = new QPushButton(this);
    but_Help->setIcon(QIcon(":/Icons/help.png"));
    but_Help->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    
    Ed = new QPlainTextEdit(this);
   

    mainGrid->addWidget(but_Open, 0, 0);
    mainGrid->addWidget(but_Save, 0, 1);
    mainGrid->addWidget(but_Settings, 0, 4);
    mainGrid->addWidget(but_Help, 0, 5);
    mainGrid->addWidget(Ed, 1, 0, 1, 6);
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

    this->setLayout(mainGrid);
   

    connect(but_Open, SIGNAL(clicked()), this, SLOT(on_but_Open_clicked()));
    connect(but_Save, SIGNAL(clicked()), this, SLOT(on_but_Save_clicked()));
    connect(but_Help, SIGNAL(clicked()), this, SLOT(on_but_Help_clicked()));
    connect(openreadA, SIGNAL(triggered()), this, SLOT(on_but_OpenOnlyRead_clicked()));
    connect(but_Settings, SIGNAL(clicked()), this, SLOT(on_but_Settings_clicked()));
    connect(setting, SIGNAL(retranslate()), this, SLOT(retranslateUI()));
    connect(setting, SIGNAL(redraw(QString, QPalette)), this, SLOT(redrawUI(QString, QPalette)));
    connect(setting, SIGNAL(com_changeOpen(unsigned int, int)), this, SLOT(switch_HKeyOpen(unsigned int, int)));
    connect(setting, SIGNAL(com_changeSave(unsigned int, int)), this, SLOT(switch_HKeySave(unsigned int, int)));
    connect(setting, SIGNAL(com_changeClear(unsigned int, int)), this, SLOT(switch_HKeyClear(unsigned int, int)));
    connect(setting, SIGNAL(com_changeExit(unsigned int, int)), this, SLOT(switch_HKeyExit(unsigned int, int)));

this->setStyleSheet(setting->getQss());

    retranslateUI();
}

void EditorTexts::keyPressEvent(QKeyEvent *event)
{
    if( (event->mods() == modOpen && event->key() == open) ||
            (modOpen == 0 && event->key() == open))
            {
        on_but_Open_clicked();
    }
    else if ( ((event->mods() ==  modSave) && event->key() == save) ||
               (modSave == 0 && event->key() == save))
               {
        on_but_Save_clicked();
    }
    else if ( ((event->mods() ==  modClear) && event->key() == clear) ||
                (modClear == 0 && event->key() == clear))
                {
        Ed->clear();
    }
    else if ( ((event->mods() == modExit) && event->key() == exit) ||
                (modExit == 0 && event->key() == exit))
                {
        qApp->exit();
    }

void EditorTexts::on_but_Open_clicked()
{
Ed->setReadOnly(false);
    QString fileName;
        try	{
        fileName = QFileDialog::getOpenFileName(this,
                tr("Open file"), QDir::currentPath(), "Files (*.* ALL)");
        }
        catch (const std::exception&)
{
                fileName = "";
        }

        if (!fileName.isEmpty())
{
            Ed->clear();
            QFile file(fileName);
            QByteArray data;
            if (!file.open(QIODevice::ReadOnly)) 
            return;
            data = file.readAll(); 
            QString txt(data);
            Ed->setPlainText(txt);
        }
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
            if (!file.open(QFile::WriteOnly | QFile::NewOnly)) 
            return;
            QTextStream stream(&file);
            stream << Ed->toPlainText();
            file.close();
        }
}

void EditorTexts::on_but_Help_clicked()
{
    QFile file(":/Txt/readme.txt");
    file.open(QIODevice::ReadOnly);
    QString info = file.readAll();
    QMessageBox::information(nullptr, tr("Help"), info);
}
void EditorTexts::on_buttonSettings_clicked()
{
    setting->show();
}

void EditorTexts::on_buttonOpenOnlyRead_clicked()
{
    on_buttonOpen_clicked();
    Ed->setReadOnly(true);
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

    setting->retranslateUI();
}

void EditorTexts::redrawUI(QString _qss, QPalette _palette)
{
    this->setPalette(_palette);
    this->setStyleSheet(_qss);
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
