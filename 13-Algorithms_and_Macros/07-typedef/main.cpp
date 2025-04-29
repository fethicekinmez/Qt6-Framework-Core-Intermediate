#include <QCoreApplication>
#include <QDebug>
#include <QMap>

typedef QMap<QString, int> customType;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    customType item;
    item.insert("Name", 33);
    item.insert("Tedx",45);
    item.insert("Fethi", 44);

    qInfo() << item; //QMap(("Fethi", 44)("Name", 33)("Tedx", 45))

    foreach (auto key, item.keys()) {
        qInfo() << key << " -> " << item[key];
    }

    /*
        "Fethi"  ->  44
        "Name"  ->  33
        "Tedx"  ->  45
     */

    return a.exec();
}



