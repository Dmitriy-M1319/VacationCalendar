#ifndef QDBCONFIG_H
#define QDBCONFIG_H

#include <QString>
#include <QSettings>

class QDbConfig
{
public:
    QDbConfig();
    QDbConfig(const QString filename);
    QDbConfig(const QString& name,
              const QString& host,
              const QString& username,
              const QString& password);
    const QString &name() const;
    const QString &host() const;
    const QString &username() const;
    const QString &password() const;
private:
    QString db_name;
    QString db_host;
    QString db_username;
    QString db_password;

};

#endif // QDBCONFIG_H
