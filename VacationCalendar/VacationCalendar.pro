QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    employee.cpp \
    employeerepository.cpp \
    main.cpp \
    mainwindow.cpp \
    qdbconfig.cpp \
    qdbhelper.cpp \
    testdatamodel.cpp \
    testrepository.cpp \
    vacation.cpp \
    vacationnorm.cpp \
    vacationnormrepository.cpp \
    vacationrepository.cpp

HEADERS += \
    employee.h \
    employeerepository.h \
    mainwindow.h \
    qdbconfig.h \
    qdbhelper.h \
    testdatamodel.h \
    testrepository.h \
    vacation.h \
    vacationnorm.h \
    vacationnormrepository.h \
    vacationrepository.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
