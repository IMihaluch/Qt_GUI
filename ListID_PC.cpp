#include "ListID_PC.h"

ListID_PC::ListID_PC(QWidget *parent) : QWidget(parent)
{

    mainGrid = new QGridLayout(this);
    condition = new QLabel(this);
    condition->setText("By clicking on the \"Select\" the background of the table cell changes");

    IDModel = new QStandardItemModel(this);
    IDModel->setColumnCount(4);
    IDModel->setHorizontalHeaderLabels(QStringList() << "№" << "Computer name" << "IP address" << "MAC address");

    for (int i =0 ; i < 5; i++) {
        standardItemsList.append(new QStandardItem(QString::number(i+1)));//№
        standardItemsList.append(new QStandardItem("Computer № "+ QString::number(i+1)));//Computer name
        standardItemsList.append(new QStandardItem("192.168.1."+ QString::number(i+10)));//IP адрес
        standardItemsList.append(new QStandardItem("AAA:AAA:AAA:AAA:AAA:AAA"));//MAC адрес
        IDModel->insertRow(IDModel->rowCount(), standardItemsList);
        standardItemsList.clear();
    }

    IDModelSelect = new QItemSelectionModel(IDModel);
    listID_PC = new QTableView(this);
    listID_PC->setModel(IDModel);
    listID_PC->setSelectionModel(IDModelSelect);
    listID_PC->resizeColumnsToContents();
    listID_PC->verticalHeader()->hide();

    buttSelect = new QPushButton(this);
    buttSelect->setText("Highlight");
    buttAdd = new QPushButton(this);
    buttAdd->setText("Add");

    mainGrid->addWidget(condition, 0, 0, 1,4);
    mainGrid->addWidget(listID_PC, 1, 0, 1,4);
    mainGrid->addWidget(buttSelect, 2, 0, 1,2);
    mainGrid->addWidget(buttAdd, 2, 2, 1,2);

    connect(buttSelect, SIGNAL(clicked()), this, SLOT(on_buttSelect_clicked()));
    connect(buttAdd, SIGNAL(clicked()), this, SLOT(on_buttAdd_clicked()));

    this->setLayout(mainGrid);
}

void  ListID_PC::on_buttSelect_clicked(){
    QModelIndexList selectedIndex = IDModelSelect->selection().indexes();
    for(int i = 0; i < selectedIndex.size(); i++)
        IDModel->itemFromIndex(selectedIndex[i])->setBackground(Qt::cyan);
}

void  ListID_PC::on_buttAdd_clicked(){
    standardItemsList.append(new QStandardItem(QString::number(IDModel->rowCount()+1)));//№
    IDModel->insertRow(IDModel->rowCount(), standardItemsList);
    standardItemsList.clear();
}
