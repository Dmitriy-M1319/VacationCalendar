#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <utility>
#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include "qganttdiagarmm.h"
#include "qdbhelper.h"
#include "qdbconfig.h"
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
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Repos::VacationNormRepository norm_repo;
    Repos::VacationRepository vac_repo;
    Repos::EmployeeRepository emp_repo;
};
#endif // MAINWINDOW_H
