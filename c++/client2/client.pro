TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    client.cpp \
    writedats.cpp \
    tcpclient.cpp

HEADERS += \
    client.h \
    writedats.h \
    rapidxml.hpp \
    rapidxml_utils.hpp \
    rapidxml_print.hpp \
    rapidxml_iterators.hpp \
    json.hpp \
    tcpclient.h

DISTFILES += \
    client.pro.user
