QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    car.cpp \
    circle.cpp \
    entername.cpp \
    game.cpp \
    gamepage.cpp \
    hs.cpp \
    main.cpp \
    scene.cpp \
    score.cpp \
    square.cpp

HEADERS += \
    Singleton.h \
    Singleton.h \
    car.h \
    circle.h \
    entername.h \
    game.h \
    gamepage.h \
    hs.h \
    scene.h \
    score.h \
    square.h

FORMS += \
    entername.ui \
    game.ui \
    gamepage.ui \
    hs.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
