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
    dialogs/addcalendrier.cpp \
    dialogs/addchambre.cpp \
    dialogs/addetudiant.cpp \
    dialogs/addlouer.cpp \
    main.cpp \
    mainwindow.cpp \
    tableDelegate/customDelegate.cpp \
    tableDelegate/format.cpp \
    widget/customCombo.cpp \
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
    dialogs/addcalendrier.h \
    dialogs/addchambre.h \
    dialogs/addetudiant.h \
    dialogs/addlouer.h \
    mainwindow.h \
    tableDelegate/customDelegate.h \
    tableDelegate/format.h \
    widget/customCombo.h \
    widget/customLineEdit.h \
    widget/customSpinBox.h

FORMS += \
    cruds/batimentcrud.ui \
    cruds/calendriercrud.ui \
    cruds/chambrecrud.ui \
    cruds/etudiantcrud.ui \
    cruds/louercrud.ui \
    dialogs/addbatiment.ui \
    dialogs/addcalendrier.ui \
    dialogs/addchambre.ui \
    dialogs/addetudiant.ui \
    dialogs/addlouer.ui \
    mainwindow.ui

INCLUDEPATH += \
    widget/ \
    cruds/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    assets/AMOLED.qss \
    assets/Aqua.qss \
    assets/ConsoleStyle.qss \
    assets/ElegantDark.qss \
    assets/LICENSE \
    assets/MacOS.qss \
    assets/ManjaroMix.qss \
    assets/MaterialDark.qss \
    assets/NeonButtons.qss \
    assets/QSS-master.zip \
    assets/QSS_IMG/go-down-symbolic.symbolic.png \
    assets/QSS_IMG/go-next-symbolic.symbolic.png \
    assets/QSS_IMG/go-previous-symbolic.symbolic.png \
    assets/QSS_IMG/go-up-symbolic.symbolic.png \
    assets/QSS_IMG/object-select-symbolic.symbolic.png \
    assets/README.md \
    assets/Ubuntu.qss

RESOURCES += \
    resources.qrc
