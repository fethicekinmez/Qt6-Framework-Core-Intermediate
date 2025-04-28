#include <QCoreApplication>
#include <QDebug>
#include "test.h"
#include "converter.h"

void writeJSON(QString path){
    Test t;
    t.fill();
    Converter::writeJSON(&t, path);
}

void readJSON(QString path){
    Test *t = Converter::readJSON(path);

    if(!t){
        qDebug() << "Could Not loaded the object";
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

    writeJSON(path);

    readJSON(path);


    return a.exec();
}
