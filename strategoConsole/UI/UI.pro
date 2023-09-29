QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boardg.cpp \
    initboard.cpp \
    main.cpp \
    mainwindow.cpp \
    squareG.cpp


HEADERS += \
    boardg.h \
    initboard.h \
    mainwindow.h \
    squareG.h \
    observer.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../metier/release/ -lmetier
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../metier/debug/ -lmetier
else:unix: LIBS += -L$$OUT_PWD/../metier/ -lmetier

INCLUDEPATH += $$PWD/../metier
DEPENDPATH += $$PWD/../metier

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../metier/release/libmetier.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../metier/debug/libmetier.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../metier/release/metier.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../metier/debug/metier.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../metier/libmetier.a
