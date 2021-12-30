QT += quick quickcontrols2

CONFIG += c++17
CONFIG += qmltypes
#QML_IMPORT_NAME = io.qt.examples.backend
#QML_IMPORT_MAJOR_VERSION = 1

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Library/Filter/fifty_fifty.cpp \
        Library/Filter/question_filter.cpp \
        Library/Filter/shuffle_answer.cpp \
        Library/Filter/shuffle_question.cpp \
        Library/Filter/topic_filter.cpp \
        Library/Question/DatabaseQuestion.cpp \
        Library/Question/Question.cpp \
        Library/Question/QuestionPack.cpp \
        Library/Scoreboard/Score.cpp \
        Library/User/DatabaseUser.cpp \
        Library/User/User.cpp \
        Library/Utility/io.cpp \
        backend.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Library/Filter/fifty_fifty.h \
    Library/Filter/filter.h \
    Library/Filter/question_filter.h \
    Library/Filter/random_generator.h \
    Library/Filter/shuffle_answer.h \
    Library/Filter/shuffle_question.h \
    Library/Filter/topic_data.h \
    Library/Filter/topic_filter.h \
    Library/Question/DatabaseQuestion.h \
    Library/Question/Question.h \
    Library/Question/QuestionPack.h \
    Library/Scoreboard/Score.h \
    Library/User/DatabaseUser.h \
    Library/User/User.h \
    Library/Utility/Mode.h \
    Library/Utility/Tokenizer.h \
    Library/Utility/constants.h \
    Library/Utility/io.h \
    Library/Utility/tinydir.h \
    backend.h

DISTFILES +=


