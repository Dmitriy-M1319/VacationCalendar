#ifndef TESTDATAMODEL_H
#define TESTDATAMODEL_H

#include <QString>

class TestDataModel
{
public:
    TestDataModel(int id, QString data);
    int id();
    QString data();
    void set_data(QString data);

private:
    int m_id;
    QString m_data;
};

#endif // TESTDATAMODEL_H
