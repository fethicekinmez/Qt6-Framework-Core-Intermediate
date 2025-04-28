#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QVariant>
#include <QVariantMap>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include "test.h"

class Converter : public QObject
{
    Q_OBJECT
public:
    explicit Converter(QObject *parent = nullptr);

    static void writeXML(Test *obj, QString path);
    static Test* readXML(QString path);

signals:
};

#endif // CONVERTER_H
