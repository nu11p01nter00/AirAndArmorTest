QT += widgets

CONFIG += c++2a

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    operationlabel.cpp \
    wpplanningcard.cpp

HEADERS += \
    GlobalEnums.h \
    GlobalTypedefs.h \
    MainWindow.h \
    operationlabel.h \
    wpplanningcard.h

FORMS += \
    MainWindow.ui \
    wpplanningcard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
