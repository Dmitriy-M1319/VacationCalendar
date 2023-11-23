#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <utility>
#include <QMainWindow>
#include <QString>
#include <QPainter>
#include <QStringList>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QLabel>
#include <QMap>
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
    QVector<std::pair<QRect, Models::Vacation>> calc_diagramm_for_employee(const Models::Employee &emp);
    void draw_diagramm_part(const QVector<std::pair<QRect, Models::Vacation>>& parts);
    void draw_gantt_lines(int employees_count);
    void draw_month_lines();
    void draw_employees_list(const QVector<Models::Employee> &emps);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QMap<int, int> normas_count;
    QDbHelper helper;
    Repos::VacationNormRepository norm_repo;
    Repos::VacationRepository vac_repo;
    Repos::EmployeeRepository emp_repo;
};
#endif // MAINWINDOW_H
