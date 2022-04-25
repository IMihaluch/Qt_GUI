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

    label = new QLabel(this);
    label->setWordWrap(true);

    layout = new QGridLayout(this);
    layout->addWidget(viev, 0, 0);
    layout->addWidget(label, 1, 0);

    this->setLayout(layout);

    connect(viev, SIGNAL(clicked(QModelIndex)), this, SLOT(push_button_3_clicked(QModelIndex)));
}

void System_viewer::push_button_3_clicked(const QModelIndex &index)
{
    QFileInfo fileInfo = model->fileInfo(index);
    QString path = fileInfo.absolutePath();
    label->setText("Directory: " + path);
}
