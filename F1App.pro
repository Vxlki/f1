QT       += core gui
QT+=network
QT+=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(Qt-QrCodeGenerator-main/Qt-QrCodeGenerator.pri)

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    a_product.cpp \
    abstractwindow.cpp \
    accesories.cpp \
    atickets.cpp \
    circuits.cpp \
    clickablelabel.cpp \
    clothing.cpp \
    databaseconnector.cpp \
    day1tickets.cpp \
    day2tickets.cpp \
    fatickets.cpp \
    functiiutile.cpp \
    i_product.cpp \
    itickets.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    merchshop.cpp \
    notloggedinwindow.cpp \
    racedaytickets.cpp \
    signinpage.cpp \
    teams.cpp \
    test.cpp \
    ticketswindow.cpp

HEADERS += \
    a_product.h \
    abstractwindow.h \
    accesories.h \
    atickets.h \
    circuits.h \
    clickablelabel.h \
    clothing.h \
    databaseconnector.h \
    day1tickets.h \
    day2tickets.h \
    fatickets.h \
    functiiutile.h \
    i_product.h \
    itickets.h \
    loginpage.h \
    mainwindow.h \
    merchshop.h \
    notloggedinwindow.h \
    racedaytickets.h \
    signinpage.h \
    teams.h \
    test.h \
    ticketswindow.h

FORMS += \
    circuits.ui \
    loginpage.ui \
    mainwindow.ui \
    merchshop.ui \
    notloggedinwindow.ui \
    signinpage.ui \
    teams.ui \
    test.ui \
    ticketswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resurse.qrc
