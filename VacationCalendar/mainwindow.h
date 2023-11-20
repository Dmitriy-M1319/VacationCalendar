#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QListWidgetItem>
#include <QMessageBox>
#include "qdbhelper.h"
#include "vacationnormrepository.h"


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
    QDbHelper helper;
    Vacations::Repositories::VacationNormRepository repo;
};
#endif // MAINWINDOW_H
