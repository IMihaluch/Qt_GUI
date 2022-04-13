#include "editortexts.h"

EditorTexts::EditorTexts(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    this->setStyleSheet(qss);

    but_Open = new QPushButton(this);
    but_Open->setIcon(QIcon(":/Icons/open.png"));
    but_Open->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    but_Open->setToolTip("Open");

    but_Save = new QPushButton(this);
    but_Save->setIcon(QIcon(":/Icons/save.png"));
    but_Save->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    but_Save->setToolTip("Save");

    but_Help = new QPushButton(this);
    but_Help->setIcon(QIcon(":/Icons/help.png"));
    but_Help->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    but_Help->setToolTip("Help");

    Ed = new QPlainTextEdit(this);
    
    mainGrid->addWidget(but_Open, 0, 0);
    mainGrid->addWidget(but_Save, 0, 1);
    mainGrid->addWidget(but_Help, 0, 5);
    mainGrid->addWidget(Ed, 1, 0, 1, 6);
    

    this->setLayout(mainGrid);
    this->setWindowTitle("Editor texts");

    connect(but_Open, SIGNAL(clicked()), this, SLOT(on_but_Open_clicked()));
    connect(but_Save, SIGNAL(clicked()), this, SLOT(on_but_Save_clicked()));
    connect(but_Help, SIGNAL(clicked()), this, SLOT(on_but_Help_clicked()));
   }

void EditorTexts::on_but_Open_clicked()
{
    QString fileName;
        try	{
        fileName = QFileDialog::getOpenFileName(this,
                "Open file", QDir::currentPath(), "Files (*.* ALL)");
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
            if (!file.open(QFile::WriteOnly | QFile::NewOnly)) 
            QTextStream stream(&file);
            stream << Ed->toPlainText();
            file.close();
        }
}

void EditorTexts::on_but_Help_clicked(){
    QFile file(":/txt/readme.txt");
    file.open(QIODevice::ReadOnly);
    QString info = file.readAll();
    QMessageBox::information(nullptr, "Help", info);
}
