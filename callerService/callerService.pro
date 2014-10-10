APP_NAME = callerService

CONFIG += qt warn_on

include(config.pri)

QT += network
LIBS += -lbb -lbbsystem -lbbplatform -lbbdata
