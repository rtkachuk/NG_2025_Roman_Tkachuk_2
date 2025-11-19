TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        parent.cpp \
        privatechild.cpp \
        protectedchild.cpp \
        publicchild.cpp

HEADERS += \
    parent.h \
    privatechild.h \
    protectedchild.h \
    publicchild.h
