#include "editortexts.h"

EditorTexts::EditorTexts(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    this->setStyleSheet(qss);

    but_Open = new QPushButton(this);
    but_Open->setIcon(QIcon(":/Icons/Icons/open.png"));
    but_Open->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    but_Open->setToolTip("Open");

    but_Save = new QPushButton(this);
    but_Save->setIcon(QIcon(":/Icons/Icons/save.png"));
    but_Save->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    but_Save->setToolTip("Save");

    but_Help = new QPushButton(this);
    but_Help->setIcon(QIcon(":/Icons/Icons/help.png"));
    but_Help->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    but_Help->setToolTip("Help");

    editor = new QPlainTextEdit(this);
    cbDark = new QCheckBox("Dark theme", this);

    mainGrid->addWidget(but_Open, 0, 0);
    mainGrid->addWidget(but_Save, 0, 1);
    mainGrid->addWidget(but_Help, 0, 5);
    mainGrid->addWidget(editor, 1, 0, 1, 6);
    mainGrid->addWidget(cbDark, 2, 0, 1, 6);

    this->setLayout(mainGrid);
    this->setWindowTitle("Editor texts");

    connect(but_Open, SIGNAL(clicked()), this, SLOT(on_but_Open_clicked()));
    connect(but_Save, SIGNAL(clicked()), this, SLOT(on_but_Save_clicked()));
    connect(but_Help, SIGNAL(clicked()), this, SLOT(on_but_Help_clicked()));
    connect(cbDark, SIGNAL(clicked()), this, SLOT(on_cbDark_clicked()));

}

void EditorTexts::on_but_Open_clicked(){
    QString fileName;
        try	{
        fileName = QFileDialog::getOpenFileName(this,
                "Open file", QDir::currentPath(), "Files (*.* ALL)");
        }
        catch (const std::exception&){
                fileName = "";
        }

        if (!fileName.isEmpty()){
            editor->clear();
            QFile file(fileName);
            QByteArray data; // сюда будем считывать данные
            if (!file.open(QIODevice::ReadOnly)) // Проверка на возможность отрытия для чтения
                            return;
            data = file.readAll(); 
            QString txt(data);
            editor->setPlainText(txt);
        }
}

void EditorTexts::on_but_Save_clicked(){
    QString fileName;
        try	{
            fileName = QFileDialog::getSaveFileName(this,
                "Save file", QDir::currentPath(), "Files (*.txt)");
        }
        catch (const std::exception&){
                fileName = "";
        }

        if (!fileName.isEmpty()){
            QFile file(fileName);
            if (!file.open(QFile::WriteOnly | QFile::NewOnly)) // Проверка на возможность открытия для записи
                            return;
            QTextStream stream(&file);
            stream << editor->toPlainText();
            file.close();
        }
}

void EditorTexts::on_but_Help_clicked(){
    QFile file(":/Txt/readme.txt");
    file.open(QIODevice::ReadOnly);
    QString info = file.readAll();
    QMessageBox::information(nullptr, "Help", info);
}

void EditorTexts::on_cbDark_clicked(){
    if (cbDark->isChecked()){
        // палитра для тёмной темы
        QPalette darkPalette;

        // Задаем палитру для цветов элементов интерфейса
        darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Text, Qt::white);
        darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::HighlightedText, Qt::black);
            // Устанавливаем палитру 
        qApp->setPalette(darkPalette);
        this->setStyleSheet(qssDark);
    }
    else{
        // Для выбора светлой палитры  устанавливаем стандартную палитру 
         qApp->setPalette(style()->standardPalette());
                  this->setStyleSheet(qss);
    }

}
