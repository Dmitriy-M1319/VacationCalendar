#include "qganttdiagarmm.h"

QGanttDiagarmm::QGanttDiagarmm(const QVector<Models::Employee> &emps,
                               const QVector<Models::VacationNorm> &normas,
                               QObject *parent)
    : QObject{parent}, m_emps{emps}, m_normas{normas}
{
    foreach (Models::VacationNorm norm, normas) {
        normas_count[norm.id()] = norm.vacations_count();
    }
}

QVector<std::pair<QRectF, Models::Vacation>> QGanttDiagarmm::calc_diagramm_for_employee(const Models::Employee &emp)
{
    QVector<std::pair<QRectF, Models::Vacation>> result;
    int days_in_year = 365;
    int y_start = (emp.id() - 1) * (LABEL_HEIGHT + 5);
    if(emp.vacations().size() != 0 && QDate::isLeapYear(emp.vacations()[0].start().year())) {
        days_in_year = 366;
    }
    float pixels_in_day = float(MONTHS_LENGTH) / days_in_year;
    foreach (const Models::Vacation& vac, emp.vacations()) {
        // Сначала необходимо вычислить начало промежутка
        float x_start = (float(MONTHS_LENGTH) * vac.start().dayOfYear() / days_in_year) +
                      (scene->width() - MONTHS_LENGTH);
        // Теперь вычисляем длину всего отрезка
        float vac_length = pixels_in_day * vac.days_count();
        QRectF diagram_rect(x_start, y_start, vac_length, LABEL_HEIGHT + 5);
        result.push_back(std::make_pair(diagram_rect, vac));

        normas_count[vac.start().month()]--;
        if(vac.start().month() != vac.end().month()) {
            normas_count[vac.end().month()]--;
        }
    }
    return result;
}

void QGanttDiagarmm::draw(QGraphicsView *view, QHBoxLayout *months)
{
    scene = new QGraphicsScene(0, 0,
                               view->width() - VIEW_SCENE_DIFF_WIDTH,
                               m_emps.size() * (LABEL_HEIGHT + 5));
    draw_month_lines();
    draw_gantt_lines();
    draw_employees_list();
    foreach (const Models::Employee& emp, m_emps) {
        auto results = calc_diagramm_for_employee(emp);
        draw_diagramm_part(results);
    }

    foreach (const Models::VacationNorm& norm, m_normas)
    {
        QLabel *label = new QLabel(norm.month());
        label->setAlignment(Qt::AlignCenter);
        if(normas_count[norm.id()] >= 0) {
            label->setStyleSheet("background-color: #52c17b");
        } else {
            label->setStyleSheet("background-color: #ff0000");
        }
        label->setMargin(0);
        months->addWidget(label);
    }
    view->setSceneRect(0, 0, view->width() - 4, m_emps.size() * (LABEL_HEIGHT + 5));
    view->setScene(scene);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    view->show();
}

void QGanttDiagarmm::draw_diagramm_part(const QVector<std::pair<QRectF, Models::Vacation>> &parts)
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

std::tuple<int, int> QGanttDiagarmm::get_first_and_last_days_numbers(int month_index)
{
    QDate start_day{QDate::currentDate().year(), month_index, 1};
    int first = start_day.dayOfYear();
    int last = start_day.addMonths(1).addDays(-1).dayOfYear();
    return std::make_tuple(first, last);
}

void QGanttDiagarmm::draw_gantt_lines()
{
    int y_start = (LABEL_HEIGHT + 5) / 2;
    int x_start = scene->width() - MONTHS_LENGTH;
    for (int i = 0; i < m_emps.size(); ++i) {
        scene->addLine(x_start, y_start, scene->width(), y_start);
        y_start += LABEL_HEIGHT + 5;
    }
}

void QGanttDiagarmm::draw_month_lines()
{
    int scene_height = scene->height();
    int scene_width = MONTHS_LENGTH;
    // Для упрощения будет получать год для текущего набор данных
    int days_in_year = 365;
    if(m_emps[0].vacations().size() != 0 && QDate::isLeapYear(m_emps[0].vacations()[0].start().year())) {
        days_in_year = 366;
    }
    float first_x = (scene->width() - MONTHS_LENGTH);
    for (int i = 0; i < 12; ++i) {
        auto dates = get_first_and_last_days_numbers(i + 1);
        float first_day_pixels = (float(scene_width) * std::get<0>(dates) / days_in_year) + first_x;
        float last_day_pixels = (float(scene_width) * std::get<1>(dates) / days_in_year) + first_x;

        QLineF line1(first_day_pixels, scene_height, first_day_pixels, 0);
        QLineF line2(last_day_pixels, scene_height, last_day_pixels, 0);
        scene->addLine(line1, QPen(Qt::black));
        scene->addLine(line2, QPen(Qt::black));
    }
}

void QGanttDiagarmm::draw_employees_list()
{
    int ystart = 0;
    int right_border = scene->width() - MONTHS_LENGTH - 1;
    foreach(const Models::Employee& emp, m_emps)
    {
        QGraphicsTextItem *txt = scene->addText(emp.get_fio(), QFont("Times", LABEL_HEIGHT - 5, QFont::Normal));
        txt->setPos(0, ystart);
        scene->addRect(0, ystart, right_border, LABEL_HEIGHT + 5, QPen(Qt::black));
        ystart += LABEL_HEIGHT + 5;
    }
    scene->addRect(0, 0, right_border, scene->height());
}
