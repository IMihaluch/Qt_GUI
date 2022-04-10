#include "proglanguage.h"

prog_language::prog_language(QWidget *parent) : QWidget(parent)
{
    list << "C++" << "Python" << "Java"<< "C#"<< "PHP"<< "JavaScript";
    listModel = new QStandardItemModel(int(list.size()), 1, this);
    for (int i = 0; i < listModel->rowCount(); ++i) {
        QModelIndex index = listModel->index(i, 0);
        QString str = list[i];
        listModel->setData(index, str,Qt::DisplayRole);
        listModel->setData(index, QIcon(":/icon/Icons/" + str + ".png"),Qt::DecorationRole);
    }

    mainGrid = new QGridLayout(this);
    condition = new QLabel(this);
    listView = new QListView(this);
    listView->setModel(listModel);
    addElement = new QPushButton(this);
    addElement->setText("Add");
    clerElement = new QPushButton(this);
    clerElement->setText("Remove");
    VieAssig = new QCheckBox(this);
    VieAssig->setText("Icon Mode");

    condition->setWordWrap(true);
    condition->setText("Names of programming languages \n");

    mainGrid->addWidget(condition, 0 ,0, 1, 6);
    mainGrid->addWidget(listView, 1, 0 , 1, 6);
    mainGrid->addWidget(addElement, 2 ,0, 1, 2);
    mainGrid->addWidget(clerElement, 2 ,2, 1, 2);
    mainGrid->addWidget(VieAssig, 2 ,4, 1, 2);

    this->setLayout(mainGrid);
    this->setWindowTitle("List of programming languages");

    connect(addElement, SIGNAL(clicked()), this, SLOT(on_addElement_clicked()));
    connect(clerElement, SIGNAL(clicked()), this, SLOT(on_clerElement_clicked()));
    connect(VieAssig, SIGNAL(clicked()), this, SLOT(on_VieAssig_clicked()));
    connect(listView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_currIndVie_clicked(QModelIndex)));


    modelListView->setDragDropMode(QAbstractItemView::InternalMove);
    listView->setDefaultDropAction(Qt::TargetMoveAction);
    listView->setMovement(QListView::Free);
}

void prog_language::on_addElement_clicked(){
    QStandardItem *item = new QStandardItem;
    item->setText("New language");
    item->setIcon(QIcon(":/icon/Icons/others.ico"));
    listModel->appendRow(item);
}

void prog_language::on_clerElement_clicked(){
//    listModel->removeRow(currInd.row());
    listModel->removeRow(listView->currentIndex().row());

}

void prog_language::on_VieAssig_clicked(){
    if(VieAssig->isChecked()) listView->setViewMode(QListView::IconMode);
    else listView->setViewMode(QListView::ListMode);
}

void prog_language::on_currIndVie_clicked(QModelIndex idx){
    Q_UNUSED(idx)
 //   currInd = idx;
}
