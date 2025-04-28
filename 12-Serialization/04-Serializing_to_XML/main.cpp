#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QDir>
#include <QFile>
#include "converter.h"

void writeXML(QString path){
    Test t;
    t.fill();
    Converter::writeXML(&t, path);
}

void readXML(QString path){
    Test *t = Converter::readXML(path);

    if(!t){
        qInfo() << "XML could Not loaded";
        return;
    }

    qInfo() << "Name: " << t->name();
    foreach (QString key, t->map().keys()) {
        qInfo() << key << " : " << t->map().value(key);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "test.txt";

    writeXML(path);

    readXML(path);


    return a.exec();
}
