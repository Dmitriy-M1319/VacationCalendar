#ifndef QDBHELPER_H
#define QDBHELPER_H

#include <QSqlDatabase>
#include <QString>
#include <QDebug>

class QDbHelper
{
public:
    QDbHelper();
    ~QDbHelper();

    bool connect(const QString& server,
                          const QString& databaseName,
                          const QString& userName,
                          const QString& password);
    const QSqlDatabase &database();
    void disconnect();

private:
    QSqlDatabase db;
};

#endif // QDBHELPER_H
