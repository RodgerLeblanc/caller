/*
 * Settings.cpp
 *
 *  Created on: 2014-09-06
 *      Author: Roger
 */

/*
 *
 * Don't forget to add this to your PRO file :
 * LIBS += -lbbdata
 *
 *
 * This is a custom object that can be used as a basic alternative to QSettings.
 * It stores everything in a JSON file. This can be helful for performance as
 * JSON is faster than QSettings in most case, and even in Ekke's tests, JSON was
 * the best choice between JSON, XML and SQL.
 *
 * To add this object to your project, follow these steps :
 * 1- Copy both Settings.cpp and Settings.h to your src folder
 * 2- In your applicationui.hpp, add those lines :
 *      #include "Settings.h"
 *
 *      private:
 *          Settings *settings;
 *
 * 3- In your application.cpp, add those lines :
 *      (in constructor)
 *      settings = new Settings(this);
 *          ...
 *      QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
 *      qml->setContextProperty("_settings", settings);
 *
 *
 */

#include "Settings.h"
#include <QFile>

Settings::Settings(QObject *_parent)
{
    // Avoid console warning as this variable is not used.
    Q_UNUSED(_parent);

    // Load the settings file on startup.
    sync();

    // If the settings file doesn't exists, create it
    QFile jsonFile(SETTINGS_FILE);
    if (!jsonFile.exists())
        save();

    // Watcher for changes in the settings file.
    watcher = new QFileSystemWatcher(this);

    // Listen for any change to the settings file, change to this file can occur if
    // another instance is modifying the file (ie: headless or UI).
    watcher->addPath(SETTINGS_FILE);
    connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(settingsChanged(QString)));
}

Settings::~Settings()
{
    // Save the settings file on exit.
    save();
}

void Settings::settingsChanged(const QString & path)
{
    // Avoid console warning as this variable is not used.
    Q_UNUSED(path);

    // Load the settings file because another instance have modified the file (headless or UI).
    sync();

    qDebug() << "UI : Settings file have changed and is now updated";
}

QStringList Settings::allKeys()
{
    // Returns a list containing all the keys in the map in ascending order.
    return settings.keys();
}

void Settings::clear()
{
    // Removes all items from the settings file.
    settings.clear();
    save();
}

bool Settings::contains(const QString &key)
{
    // Returns true if the settings file contains an item with key key;
    // otherwise returns false.
    return settings.contains(key);
}

QString Settings::fileName()
{
    return SETTINGS_FILE;
}

int Settings::remove(const QString &key)
{
    // Removes all the items that have the key key from the settings file.
    // Returns the number of items removed which is usually 1 but will be 0
    // if the key isn't in the settings file.

    return settings.remove(key);
}

void Settings::save()
{
    jda.save(QVariant(settings), SETTINGS_FILE);
}

void Settings::setValue(const QString &key, const QVariant &value)
{
    // Inserts a new item with the key key and a value of value.
    // If there is already an item with the key key, that item's value is
    // replaced with value.

    qDebug() << "Settings::setValue ->" << key << ":" << value;

    settings.insert(key, value);
    save();
}

void Settings::sync()
{
    // Reloads any settings that have been changed by another application.
    // This function is called automatically by the event loop at regular intervals,
    // so you normally don't need to call it yourself.
    settings = jda.load(SETTINGS_FILE).toMap();
}

QVariant Settings::value(const QString &key, const QVariant &defaultValue)
{
    // Returns the value associated with the key key.
    // If the settings file contains no item with key key,
    // the function returns defaultValue.

    // Return on empty key.
    if (key.trimmed().isEmpty())
        return QVariant();

    if (settings.contains(key)) {
        qDebug() << "Settings::value ->" << key << ":" << settings.value(key);
        return settings.value(key);
    }
    else
        return defaultValue;
}
