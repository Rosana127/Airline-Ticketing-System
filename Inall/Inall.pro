QT       += core gui
QT+=sql
#测试用例1111
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buymenu.cpp \
    cancelorderwindow.cpp \
    chooseair.cpp \
    database.cpp \
    flight_add2.cpp \
    flight_change.cpp \
    flight_chaninfo.cpp \
    flight_delete.cpp \
    flightinfopage.cpp \
    flisingle.cpp \
    forgetpassword.cpp \
    forgetpassword2.cpp \
    global.cpp \
    homemanager.cpp \
    homepage.cpp \
    inboxwindow2.cpp \
    inquire.cpp \
    login.cpp \
    main.cpp \
    manager1226.cpp \
    managerticket.cpp \
    manorder.cpp \
    myorders.cpp \
    myticket.cpp \
    passengerinfopage.cpp \
    paymentpage.cpp \
    qcustomcalendarwidget.cpp \
    ratingwindow.cpp \
    registerdialog2.cpp \
    seatsselectpage.cpp \
    side.cpp \
    ticketwindow.cpp \
    userinfopage.cpp

HEADERS += \
    buymenu.h \
    cancelorderwindow.h \
    chooseair.h \
    database.h \
    flight_add2.h \
    flight_change.h \
    flight_chaninfo.h \
    flight_delete.h \
    flightinfopage.h \
    flisingle.h \
    forgetpassword.h \
    forgetpassword2.h \
    global.h \
    homemanager.h \
    homepage.h \
    inboxwindow2.h \
    inquire.h \
    login.h \
    manager1226.h \
    managerticket.h \
    manorder.h \
    myorders.h \
    myticket.h \
    myticket2.h \
    passengerinfopage.h \
    paymentpage.h \
    qcustomcalendarwidget.h \
    ratingwindow.h \
    registerdialog2.h \
    seatsselectpage.h \
    side.h \
    ticketwindow.h \
    userinfopage.h

FORMS += \
    buymenu.ui \
    cancelorderwindow.ui \
    chooseair.ui \
    flight_add2.ui \
    flight_change.ui \
    flight_chaninfo.ui \
    flight_delete.ui \
    flightinfopage.ui \
    flisingle.ui \
    forgetpassword.ui \
    forgetpassword2.ui \
    homemanager.ui \
    homepage.ui \
    inboxwindow2.ui \
    inquire.ui \
    login.ui \
    manager1226.ui \
    managerTicket.ui \
    manorder.ui \
    myorders.ui \
    myticket.ui \
    myticket12.ui \
    passengerinfopage.ui \
    paymentpage.ui \
    ratingwindow.ui \
    registerdialog2.ui \
    seatsselectpage.ui \
    side.ui \
    userinfopage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES +=


