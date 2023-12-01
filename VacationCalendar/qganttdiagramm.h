#ifndef QGANTTDIAGRAMM_H
#define QGANTTDIAGRAMM_H

#include <chrono>
#include <tuple>
#include <utility>
#include <QObject>
#include <QDate>
#include <QRect>
#include <QLabel>
#include <QPoint>
#include <QScrollBar>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QMap>
#include <QString>
#include <QVector>
#include "vacation.h"
#include "vacationnorm.h"
#include "employee.h"

#define LABEL_HEIGHT 20
#define MONTHS_LENGTH 1080
#define VIEW_SCENE_DIFF_WIDTH 4
#define VIEW_SCENE_DIFF_HEIGHT 12

namespace Models = Vacations::Models;

class QGanttDiagramm : public QObject
{
    Q_OBJECT
public:
    explicit QGanttDiagramm(const QVector<Models::Employee> &emps,
                            const QVector<Models::VacationNorm> &normas,
                            QObject *parent = nullptr);
    void draw(QGraphicsView *view, QHBoxLayout *months);
signals:

private:
    QObject *m_months;
    QGraphicsScene *scene;
    QMap<int, int> normas_count;
    QVector<Models::Employee> m_emps;
    QVector<Models::VacationNorm> m_normas;

    void draw_diagramm_part(const QVector<std::pair<QRectF, Models::Vacation>>& parts);
    std::tuple<int, int> get_first_and_last_days_numbers(int month_index);
    void draw_month_lines();
    void draw_employees_list();
    QVector<std::pair<QRectF, Models::Vacation>> calc_diagramm_for_employee(const Models::Employee &emp);
};

#endif // QGANTTDIAGRAMM_H
