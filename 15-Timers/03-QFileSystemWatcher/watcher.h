#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <QFileSystemWatcher>

class Watcher : public QObject
{
    Q_OBJECT

    QFileSystemWatcher fsw;
public:
    explicit Watcher(QObject *parent = nullptr);

public slots:
    void fileChanged(const QString &path);
    void directoryChanged(const QString &path);


signals:
};

#endif // WATCHER_H
