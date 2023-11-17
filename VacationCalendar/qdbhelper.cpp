#include "qdbhelper.h"

QDbHelper::QDbHelper()
{

}

QSqlDatabase* QDbHelper::connect(const QString& server,
                                    const QString& databaseName,
                                    const QString& userName,
                                    const QString& password )
{
    db->setConnectOptions();
    db->setHostName(server);
    db->setDatabaseName(databaseName);
    db->setUserName(userName);
    db->setPassword(password);

    if(db->open()) {
        return db;
    }
    else {
        return NULL;
    }
}

void QDbHelper::disconnect()
{
    qDebug() << "Disconnected From Database!";
    db->close();
}
