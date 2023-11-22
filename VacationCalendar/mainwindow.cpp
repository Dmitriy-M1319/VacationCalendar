#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    foreach (Models::VacationNorm norm, normas) {
        normas_count[norm.id()] = norm.vacations_count();
    }
    auto employees = emp_repo.get_employees();
    for (int i = 0; i < employees.size(); ++i)
    {
        employees[i].set_vacations(vac_repo.get_vacations_for_employee(employees[i].id()));
    }

    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0,
                               ui->graphicsView->width() - VIEW_SCENE_DIFF_WIDTH,
                               ui->graphicsView->height() - VIEW_SCENE_DIFF_HEIGHT);
    draw_month_lines();
    draw_employees_list(employees);
    foreach (const Models::Employee& emp, employees) {
        auto results = calc_diagramm_for_employee(emp);
        draw_diagramm_part(results);
    }

    foreach (const Models::VacationNorm& norm, normas)
    {
        QLabel *label = new QLabel(norm.month());
        label->setAlignment(Qt::AlignCenter);
        if(normas_count[norm.id()] >= 0) {
            label->setStyleSheet("background-color: #00ff01");
        } else {
            label->setStyleSheet("background-color: #ff0000");
        }
        label->setMargin(0);
        ui->monthsLayout->addWidget(label);
    }
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

QVector<std::pair<QRect, Models::Vacation>> MainWindow::calc_diagramm_for_employee(const Models::Employee &emp)
{
    QVector<std::pair<QRect, Models::Vacation>> result;
    int days_in_year = 365;
    int y_start = (emp.id() - 1) * (LABEL_HEIGHT + 5);
    if(emp.vacations().size() != 0 && QDate::isLeapYear(emp.vacations()[0].start().year())) {
        days_in_year = 366;
    }
    int pixels_in_day = MONTHS_LENGTH / days_in_year;
    foreach (const Models::Vacation& vac, emp.vacations()) {
        // Сначала необходимо вычислить начало промежутка
        int x_start = (MONTHS_LENGTH * vac.start().dayOfYear() / days_in_year) +
                      (scene->width() - MONTHS_LENGTH);
        // Теперь вычисляем длину всего отрезка
        int vac_length = pixels_in_day * vac.days_count();
        QRect diagram_rect(x_start, y_start, vac_length, LABEL_HEIGHT + 5);
        result.push_back(std::make_pair(diagram_rect, vac));

        normas_count[vac.start().month()]--;
        if(vac.start().month() != vac.end().month()) {
            normas_count[vac.end().month()]--;
        }
    }
    return result;
}

void MainWindow::draw_diagramm_part(const QVector<std::pair<QRect, Models::Vacation>> &parts)
{
    foreach (const auto& part, parts) {
        scene->addRect(part.first, QPen(Qt::black));
        QLabel* label = new QLabel(QString("%1").arg(part.second.days_count()));
        label->setAlignment(Qt::AlignCenter);
        label->setFixedSize(part.first.width() - 1, part.first.height()- 1);
        label->setMouseTracking(true);
        label->setToolTip(QString("Дата начала: %1\nДата окончания: %2")
                              .arg(part.second.start().toString("d MMMM yyyy"),
                                   part.second.end().toString("d MMMM yyyy")));
        scene->addWidget(label);
        label->move(QPoint(part.first.x() + 1, part.first.y() + 1));

    }
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

