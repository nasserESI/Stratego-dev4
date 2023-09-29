TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
include (../config.pri)

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
HEADERS += \
    catch.hpp

SOURCES += \
    boardTest.cpp \
    main.cpp \
    pieceTest.cpp \
    squareTest.cpp \
    strategoTest.cpp
