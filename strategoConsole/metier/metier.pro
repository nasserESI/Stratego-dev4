TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17
TARGET = metier
include (../config.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Color.cpp \
    HistoricalMove.cpp \
    Move.cpp \
    Position.cpp \
    board.cpp \
    main.cpp \
    piece.cpp \
    player.cpp \
    square.cpp \
    stratego.cpp \
    subject.cpp


HEADERS += \
    Color.h \
    HistoricalMove.h \
    Move.h \
    Position.h \
    State.h \
    TypePiece.h \
    TypeSquare.h \
    access_exception.h \
    board.h \
    piece.h \
    player.h \
    stratego.h \
    square.h \
    subject.h \
    observer.h


# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
