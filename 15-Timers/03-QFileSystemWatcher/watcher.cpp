#include "watcher.h"

Watcher::Watcher(QObject *parent) : QObject{parent}{
    fsw.addPath(QDir::currentPath());
    fsw.addPath(QDir::currentPath() + QDir::separator() + "test.txt");

    QObject::connect(&fsw, &QFileSystemWatcher::fileChanged, this, &Watcher::fileChanged);
    QObject::connect(&fsw, &QFileSystemWatcher::directoryChanged, this, &Watcher::directoryChanged);
}

void Watcher::fileChanged(const QString &path)
{
    qInfo() << "File changed: " << path;

    if(fsw.files().length()){
        qInfo() << "Files that have changed:";
        foreach (QString file, fsw.files()) {
            qInfo() << file;
        }
    }
}

void Watcher::directoryChanged(const QString &path)
{
    qInfo() << "Directory changed: " << path;

    if(fsw.directories().length()){
        qInfo() << "Directories that have changed:";
        foreach (QString directory, fsw.directories()) {
            qInfo() << directory;
        }
    }
}
