#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QDbConfig config{};
    QDbHelper helper;
    if(!helper.connect(config.host(),config.name(),config.username(), config.password()))
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
    QGanttDiagramm diagramm{employees, normas};
    diagramm.draw(ui->graphicsView, ui->monthsLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

