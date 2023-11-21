#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //TODO: Вынести данные подключения к БД в отдельный конфиг
    if(!helper.connect("localhost",
                      "vacations",
                       "postgres",
                       "12345"))
    {
        QMessageBox msgBox;
        msgBox.setText("Failed to open database connection.");
        msgBox.exec();
    }
    norm_repo.set_db(helper.database());
    emp_repo.set_db(helper.database());
    vac_repo.set_db(helper.database());
    auto normas = norm_repo.get_all_normas();
    auto employees = emp_repo.get_employees();
    for (int i = 0; i < employees.size(); ++i)
    {
        employees[i].set_vacations(vac_repo.get_vacations_for_employee(employees[i].id()));
    }

    ui->setupUi(this);
    prepare_table(employees, normas);
}

void MainWindow::prepare_table(const QVector<Models::Employee> &emps,
                               const QVector<Models::VacationNorm> &normas)
{
    ui->vacations_table->setRowCount(emps.size());
    ui->vacations_table->setColumnCount(normas.size());
    for (int row = 0; row < emps.size(); ++row)
    {
        for (int month_index = 0; month_index < normas.size(); ++month_index)
        {
            int days_count = emps[row].get_vacation_days_count(month_index + 1);
            //TODO: Сделать вывод каждой части отпуска в своем месяце
            QString tArg = "";
            if(days_count != 0)
            {
                tArg = QString("%1").arg(days_count);
            }
            QTableWidgetItem *vacationItem = new QTableWidgetItem(tArg);
            ui->vacations_table->setItem(row, month_index, vacationItem);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

