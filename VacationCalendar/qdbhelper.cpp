#include "qdbhelper.h"

QDbHelper::QDbHelper()
{

}

bool QDbHelper::connect(const QString& server,
                                    const QString& databaseName,
                                    const QString& userName,
                                    const QString& password )
{
    db.setConnectOptions();
    db.setHostName(server);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);
    db.setPassword(password);

    return db.open();
}

const QSqlDatabase &QDbHelper::database()
{
    return this->db;
}

void QDbHelper::disconnect()
{
    qDebug() << "Disconnected From Database!";
    db.close();
}
