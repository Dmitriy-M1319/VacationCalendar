#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QListWidgetItem>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include "qdbhelper.h"
#include "vacationnormrepository.h"
#include "vacationrepository.h"
#include "employeerepository.h"

namespace Repos = Vacations::Repositories;
namespace Models = Vacations::Models;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void prepare_table(const QVector<Models::Employee> &emps,
                       const QVector<Models::VacationNorm> &normas);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QDbHelper helper;
    Repos::VacationNormRepository norm_repo;
    Repos::VacationRepository vac_repo;
    Repos::EmployeeRepository emp_repo;
};
#endif // MAINWINDOW_H
