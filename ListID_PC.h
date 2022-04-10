#ifndef LISTID_PC_H
#define LISTID_PC_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QListView>

class  ListID_PC : public QWidget
{
    Q_OBJECT
public:
    explicit  ListID_PC(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; 
    QLabel *condition;
    QTableView *listID_PC;
    QStandardItemModel *IDModel;
    QPushButton *buttSelect;
    QPushButton *buttAdd;

    QItemSelectionModel* IDModelSelect;

    QList<QStandardItem *> standardItemsList; 
signals:

public slots:
    void on_buttSelect_clicked(); 
    void on_buttAdd_clicked();
};

#endif // LISTID_PC_H
