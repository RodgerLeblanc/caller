/*
 * Settings.h
 *
 *  Created on: 2014-09-06
 *      Author: Roger
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <QObject>
#include <bb/data/JsonDataAccess>
#include <QFileSystemWatcher>
#include <QStringList>

#define SETTINGS_FILE "data/settings.json"
#define SETTINGS_ERROR "ERROR IN KEY NAME"

class Settings : public QObject
{
    Q_OBJECT
public:
    Settings(QObject *_parent = 0);
    virtual ~Settings();

    Q_INVOKABLE QStringList allKeys();
    Q_INVOKABLE bool contains(const QString &key);
    Q_INVOKABLE void clear();
    Q_INVOKABLE QString fileName();
    Q_INVOKABLE int remove(const QString &key);
    Q_INVOKABLE void setValue(const QString &key, const QVariant &value);
    Q_INVOKABLE void sync();
    Q_INVOKABLE QVariant value(const QString &key, const QVariant &defaultValue = QVariant());

private slots:
    void settingsChanged(const QString & path);

private:
    void save();

    QFileSystemWatcher* watcher;

    bb::data::JsonDataAccess jda;
    QVariantMap settings;
};

#endif /* SETTINGS_H_ */

