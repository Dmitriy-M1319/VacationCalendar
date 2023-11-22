#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#define LABEL_HEIGHT 20
#define MONTHS_LENGTH 1080
#define VIEW_SCENE_DIFF_WIDTH 4
#define VIEW_SCENE_DIFF_HEIGHT 12

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
    scene = new QGraphicsScene(0, 0,
                               ui->graphicsView->width() - VIEW_SCENE_DIFF_WIDTH,
                               ui->graphicsView->height() - VIEW_SCENE_DIFF_HEIGHT);
    foreach (const Models::VacationNorm& norm, normas)
    {
        QLabel *label = new QLabel(norm.month());
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(0);
        ui->monthsLayout->addWidget(label);
    }

    draw_month_lines();
    draw_employees_list(employees);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void MainWindow::draw_month_lines()
{
    int scene_height = scene->height();
    int scene_width = MONTHS_LENGTH;
    qDebug() << scene_height << scene_width;
    int month_length = scene_width / 12;
    float first_x = (scene->width() - MONTHS_LENGTH) + month_length / 2;
    for (int i = 0; i < 12; ++i) {
        QLineF line(first_x,
               scene_height,
               first_x,
               scene_width - 10);
        scene->addLine(line, QPen(Qt::black));
        first_x += month_length;
    }
    //scene->addRect(0, 0, 40, 40, QPen(Qt::black), QBrush(Qt::red));
}

void MainWindow::draw_employees_list(const QVector<Models::Employee> &emps)
{
    int ystart = 0;
    int right_border = scene->width() - MONTHS_LENGTH - 1;
    foreach(const Models::Employee& emp, emps)
    {
        QGraphicsTextItem *txt = scene->addText(emp.get_fio(), QFont("Times", LABEL_HEIGHT - 5, QFont::Normal));
        txt->setPos(0, ystart);
        scene->addRect(0, ystart, right_border, LABEL_HEIGHT + 5, QPen(Qt::black));
        ystart += LABEL_HEIGHT + 5;
    }
    scene->addRect(0, 0, right_border, scene->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

