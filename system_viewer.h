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
#include <QtConcurrent>
#include <QListWidget>
#include <QFuture>
#include <QLineEdit>
#include <QSplitter>

#include "serch.h"

Q_PROPERTY(QStandardItemModel *model READ getCurrentModel WRITE setNewModel)

class System_viewer : public QWidget
{
    Q_OBJECT
public:
    explicit System_viewer(QWidget *parent = nullptr);

private:
       QGridLayout *layout {nullptr};
       QTreeView *viev {nullptr};
       QFileSystemModel *model {nullptr};
       QLabel *label {nullptr};

       QLineEdit *edit {nullptr};
       QPushButton *serch {nullptr};
       QListWidget *result {nullptr};
       QSplitter *splitter {nullptr};
       QString path;

public slots:
       
       void on_serch_clicked();
       void addSerchFile(QString pathFile);

protected:


};

#endif // SYSTEM_VIEWER_H
