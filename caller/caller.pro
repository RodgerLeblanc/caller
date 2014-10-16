APP_NAME = caller

CONFIG += qt warn_on cascades10

include(config.pri)

LIBS += -lbb -lbbsystem -lbbdata

TRANSLATIONS = \
    $${TARGET}_fr.ts \
    $${TARGET}.ts