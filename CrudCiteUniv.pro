QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cruds/batimentcrud.cpp \
    cruds/calendriercrud.cpp \
    cruds/chambrecrud.cpp \
    cruds/etudiantcrud.cpp \
    cruds/louercrud.cpp \
    database/db.cpp \
    dialogs/addbatiment.cpp \
    dialogs/addetudiant.cpp \
    main.cpp \
    mainwindow.cpp \
    tableDelegate/customDelegate.cpp \
    tableDelegate/format.cpp \
    widget/customLineEdit.cpp \
    widget/customSpinBox.cpp

HEADERS += \
    cruds/batimentcrud.h \
    cruds/calendriercrud.h \
    cruds/chambrecrud.h \
    cruds/etudiantcrud.h \
    cruds/louercrud.h \
    database/db.h \
    dialogs/addbatiment.h \
    dialogs/addetudiant.h \
    mainwindow.h \
    tableDelegate/customDelegate.h \
    tableDelegate/format.h \
    widget/customLineEdit.h \
    widget/customSpinBox.h

FORMS += \
    cruds/batimentcrud.ui \
    cruds/calendriercrud.ui \
    cruds/chambrecrud.ui \
    cruds/etudiantcrud.ui \
    cruds/louercrud.ui \
    dialogs/addbatiment.ui \
    dialogs/addetudiant.ui \
    mainwindow.ui

INCLUDEPATH += \
    widget/ \
    cruds/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
