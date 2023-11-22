#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
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
    void draw_month_lines();
    void draw_employees_list(const QVector<Models::Employee> &emps);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QDbHelper helper;
    Repos::VacationNormRepository norm_repo;
    Repos::VacationRepository vac_repo;
    Repos::EmployeeRepository emp_repo;
};
#endif // MAINWINDOW_H
