#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    if(!helper.connect("localhost",
                      "vacations",
                       "postgres",
                       "12345"))
    {
        QMessageBox msgBox;
        msgBox.setText("Failed to open database connection.");
        msgBox.exec();
    }
    repo.set_db(helper.database());
    auto normas = repo.get_all_normas();

    ui->setupUi(this);
    foreach (const Vacations::Models::VacationNorm& norm, normas)
    {
        QStringList info{};
        info << "ID: " << QString("%1").arg(norm.id()) << ", month: " << norm.month() << ", count: " << QString("%1").arg(norm.vacations_count());
        new QListWidgetItem(info.join(""), ui->normas_list);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

