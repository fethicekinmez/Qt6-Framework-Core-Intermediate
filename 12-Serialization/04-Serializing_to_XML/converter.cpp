#include "converter.h"



Converter::Converter(QObject *parent) : QObject{parent}{

}

void Converter::writeXML(Test *obj, QString path){
    QFile file(path);
    if(!file.open(QIODeviceBase::WriteOnly)){
        qCritical() << "Could not open the file (wirte)";
        qCritical() << file.errorString();
        return;
    }

    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);

    stream.writeStartDocument();
    stream.writeStartElement("test");
    stream.writeAttribute("name", obj->name());
    stream.writeStartElement("items");

    foreach(QString key, obj->map().keys()){
        stream.writeStartElement("item");
        stream.writeAttribute("key", key);
        stream.writeAttribute("value", obj->map().value(key));
        stream.writeEndElement();
    }

    stream.writeEndElement();
    stream.writeEndElement();
    stream.writeEndDocument();

    file.close();
}

Test *Converter::readXML(QString path){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could Not open the file (read)";
        qCritical() << file.errorString();
        return nullptr;
    }

    QByteArray data = file.readAll();
    file.close();

    QXmlStreamReader stream(data);
    Test *t = new Test();
    QMap<QString, QString> map;
    while(!stream.atEnd()){
        QXmlStreamReader::TokenType token = stream.readNext();

        switch (token) {
        case QXmlStreamReader::Comment:
            break;
        case QXmlStreamReader::DTD:
            break;
        case QXmlStreamReader::Characters:
            break;
        case QXmlStreamReader::ProcessingInstruction:
            break;
        case QXmlStreamReader::EntityReference:
            break;
        case QXmlStreamReader::NoToken:
            break;
        case QXmlStreamReader::Invalid:
            break;
        case QXmlStreamReader::StartDocument:
            break;
        case QXmlStreamReader::EndDocument:
            t->setMap(map);
            break;
        case QXmlStreamReader::StartElement:
            if(stream.name().toString() == "test")
            {
                QString name = stream.attributes().value("name").toString();
                t->setName(name);
            }
            if(stream.name().toString() == "item")
            {
                QString key = stream.attributes().value("key").toString();
                QString value = stream.attributes().value("value").toString();
                map.insert(key,value);
            }

            break;
        case QXmlStreamReader::EndElement:
            break;
        }

    }

    return t;
}
