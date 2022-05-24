#include "System_viewer.h"

System_viewer::System_viewer(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("File System Viewer");


    model = new QFileSystemModel(this);
    model->setFilter(QDir::AllEntries);
    model->setRootPath("");
    model->setResolveSymlinks(false);

    viev = new QTreeView(this);
    viev->setModel(model);

    result = new QListWidget(this);
    splitter = new QSplitter(Qt::Vertical);

    label = new QLabel(this);
    label->setWordWrap(true);

    edit = new QLineEdit(this);
    edit->setText("");
    serch = new QPushButton(this);
    serch->setText("Search");

    layout = new QGridLayout(this);
    layout->addWidget(viev, 0, 0, 1,4);
    layout->addWidget(label, 1, 0, 1,4);
    layout->addWidget(edit, 2, 0, 1,3);
    layout->addWidget(serch, 2, 3);

    QWidget *centralWgt = new QWidget(this);
    centralWgt->setLayout(gridLay);
    splitter->addWidget(centralWgt);
    splitter->addWidget(result);

    QGridLayout *mainGrid = new QGridLayout(this);
    mainGrid->addWidget(splitter);

    this->setLayout(mainGrid);
    this->setMinimumSize(600, 400);
    connect(viev, SIGNAL(clicked(QModelIndex)), this, SLOT(push_button_3_clicked(QModelIndex)));
connect(serch, SIGNAL(clicked()), this, SLOT(on_serch_clicked()));
}

void System_viewer::push_button_3_clicked(const QModelIndex &index)
{
    QFileInfo fileInfo = model->fileInfo(index);
    path = fileInfo.absolutePath();
    label->setText("Directory search: " + path);
}

void System_viewer::on_serch_clicked()
{
     result->clear();
     SerchFiles *files = new SerchFiles(this);
     connect(files, SIGNAL(foundFile(QString)), this, SLOT(addSerchFile(QString)));
     QThread* thread = QThread::create(std::bind(&SerchFiles::startSerching, files, path, edit->text()));
     thread->start();
}

void System_viewer::addSerchFile(QString pathFile)
{
    result->addItem(pathFile);
}
