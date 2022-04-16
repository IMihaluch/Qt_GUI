#ifndef PROG_LANGUAGE_H
#define PROG_LANGUAGE_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QListView>

class prog_language : public QWidget
{
    Q_OBJECT
public:
    explicit prog_language(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid;
    QLabel *condition;
    QListView *listView;
    QPushButton *addElement; 
    QPushButton *clerElement;  
    QCheckBox *VieAssig; 

    QStandardItemModel *listModel;
    QStringList list;
    QModelIndex currInd; 
signals:

public slots:
    void on_addElement_clicked();
    void on_clerElement_clicked();
    void on_VieAssig_clicked();
    void on_currIndVie_clicked(QModelIndex idx);
};

#endif // PROGLANGUAGE_H
