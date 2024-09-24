#include "qdbconfig.h"

QDbConfig::QDbConfig(): QDbConfig::QDbConfig(QString("../settings.ini"))
{
}

QDbConfig::QDbConfig(const QString filename)
{
    QSettings settings(filename, QSettings::IniFormat);
    db_name = settings.value("POSTGRES_DB", "").toString();
    db_host = settings.value("POSTGRES_HOST", "").toString();
    db_username = settings.value("POSTGRES_USER", "").toString();
    db_password = settings.value("POSTGRES_PASSWORD", "").toString();
}

QDbConfig::QDbConfig(const QString &name,
                     const QString &host,
                     const QString &username,
                     const QString &password):
    db_name(name), db_host(host), db_username(username), db_password(password)
{
}

const QString &QDbConfig::name() const
{
    return db_name;
}

const QString &QDbConfig::host() const
{
    return db_host;
}

const QString &QDbConfig::username() const
{
    return db_username;
}

const QString &QDbConfig::password() const
{
    return db_password;
}
