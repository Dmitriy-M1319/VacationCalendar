#ifndef QDBHELPER_H
#define QDBHELPER_H

#include <QSql>
#include <QString>
#include <QDebug>

class QDbHelper
{
public:
    QDbHelper();
    ~QDbHelper();

    QSqlDatabase* connect( const QString& server,
                          const QString& databaseName,
                          const QString& userName,
                          const QString& password );
    void disconnect();

private:
    QSqlDatabase *db;
};

#endif // QDBHELPER_H
