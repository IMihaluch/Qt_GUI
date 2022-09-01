#ifndef ORGANIZERMOD_H
#define ORGANIZERMOD_H

#include <QStandardItemModel>
#include <QAbstractItemModel>
#include <QObject>
#include <QString>
#include <QVector>
#include <QVariantList>
#include <QTextCodec>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>

class Organizermod : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit Organizermod(QObject *parent = nullptr);

    
    ~Organizermod() override;

    Q_INVOKABLE void addObject(QString _name, QString _deadLine, QString _progress);
    Q_INVOKABLE void addObjectFromBD();
    Q_INVOKABLE void delObject(const QModelIndex & index);
    Q_INVOKABLE void delData();

signals:


public slots:

private:
     QSqlDatabase database;
};

#endif // ORGANIZERMOD_H
