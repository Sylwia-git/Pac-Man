TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:/SFML-2.6.1/include"
LIBS += -L"C:/SFML-2.6.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
        characters.cpp \
        ghosts.cpp \
        main.cpp \
        pacman.cpp \
        walls_and_balls.cpp

HEADERS += \
    characters.h \
    ghosts.h \
    pacman.h \
    walls_and_balls.h
