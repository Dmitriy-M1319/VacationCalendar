#include "testdatamodel.h"

TestDataModel::TestDataModel(int id, QString data) {
    this->m_id = id;
    this->m_data = data;
}

int TestDataModel::id() {
    return this->m_id;
}

QString TestDataModel::data() {
    return this->m_data;
}

void TestDataModel::set_data(QString data) {
    this->m_data = data;
}

