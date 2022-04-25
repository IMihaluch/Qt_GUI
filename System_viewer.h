#ifndef SYSTEM_VIEWER_H
#define SYSTEM_VIEWER_H

#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QApplication>
#include <QFileInfo>
#include <QDir>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QLabel>

Q_PROPERTY(QStandardItemModel *model READ getCurrentModel WRITE setNewModel)

class System_viewer : public QWidget
{
    Q_OBJECT
public:
    explicit System_viewer(QWidget *parent = nullptr);

private:
       QGridLayout *layout;
       QTreeView *viev;
       QFileSystemModel *model;
       QLabel *label;

public slots:
       void push_button_3_clicked(const QModelIndex &index);

protected:


};

#endif // SYSTEM_VIEWER_H
