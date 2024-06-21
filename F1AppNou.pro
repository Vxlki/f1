QT+=core
QT+=gui
QT+=network
QT+=sql
QT+=multimedia
QT+=multimediawidgets
QT+=svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(Qt-QrCodeGenerator-main/Qt-QrCodeGenerator.pri)


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    a_personnel.cpp \
    a_product.cpp \
    abstractwindow.cpp \
    accesories.cpp \
    atickets.cpp \
    autologin.cpp \
    c_address.cpp \
    c_circuits.cpp \
    c_drivers.cpp \
    c_engineers.cpp \
    c_headquarters.cpp \
    c_manager.cpp \
    c_teams.cpp \
    c_user.cpp \
    circuits.cpp \
    clickablelabel.cpp \
    clothing.cpp \
    databaseconnector.cpp \
    day1tickets.cpp \
    day2tickets.cpp \
    fatickets.cpp \
    functiiutile.cpp \
    grandprixwindow.cpp \
    i_personnel.cpp \
    i_product.cpp \
    itickets.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    merchshop.cpp \
    notloggedinwindow.cpp \
    pages.cpp \
    productframe.cpp \
    profilewindow.cpp \
    racedaytickets.cpp \
    serverconnection.cpp \
    signinpage.cpp \
    teams.cpp \
    test.cpp \
    ticketframe.cpp \
    ticketsbuywindow.cpp \
    ticketswindow.cpp

HEADERS += \
    a_personnel.h \
    a_product.h \
    abstractwindow.h \
    accesories.h \
    atickets.h \
    autologin.h \
    c_address.h \
    c_circuits.h \
    c_drivers.h \
    c_engineers.h \
    c_headquarters.h \
    c_manager.h \
    c_teams.h \
    c_user.h \
    circuits.h \
    clickablelabel.h \
    clothing.h \
    databaseconnector.h \
    day1tickets.h \
    day2tickets.h \
    fatickets.h \
    functiiutile.h \
    grandprixwindow.h \
    i_personnel.h \
    i_product.h \
    itickets.h \
    loginpage.h \
    mainwindow.h \
    merchshop.h \
    notloggedinwindow.h \
    pages.h \
    productframe.h \
    profilewindow.h \
    racedaytickets.h \
    serverconnection.h \
    signinpage.h \
    teams.h \
    test.h \
    ticketframe.h \
    ticketsbuywindow.h \
    ticketswindow.h

FORMS += \
    circuits.ui \
    grandprixwindow.ui \
    loginpage.ui \
    mainwindow.ui \
    merchshop.ui \
    notloggedinwindow.ui \
    productframe.ui \
    profilewindow.ui \
    serverconnection.ui \
    signinpage.ui \
    teams.ui \
    test.ui \
    ticketframe.ui \
    ticketsbuywindow.ui \
    ticketswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resurse.qrc

SUBDIRS += \
    ../Server/Server.pro

DISTFILES +=
