#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QList<Test*> list;
    for(int i=0; i<10; i++){
        Test *t = new Test(); // no smart pointer, no parent
        t->setObjectName(QString::number(i));
        list.append(t);
    }

    qInfo() << list.count() << " number of elements";

    qDeleteAll(list);
    list.clear();

    qInfo() << list.count() << " number of elements";

    return a.exec();
}

/*
Constructed:  Test(0x60000134c070)
Constructed:  Test(0x60000134c100)
Constructed:  Test(0x60000134c110)
Constructed:  Test(0x60000134c120)
Constructed:  Test(0x60000134c130)
Constructed:  Test(0x60000134c140)
Constructed:  Test(0x60000134c150)
Constructed:  Test(0x60000134c160)
Constructed:  Test(0x60000134c170)
Constructed:  Test(0x60000134c180)
10  number of elements
Deconstructed:  Test(0x60000134c070, name = "0")
Deconstructed:  Test(0x60000134c100, name = "1")
Deconstructed:  Test(0x60000134c110, name = "2")
Deconstructed:  Test(0x60000134c120, name = "3")
Deconstructed:  Test(0x60000134c130, name = "4")
Deconstructed:  Test(0x60000134c140, name = "5")
Deconstructed:  Test(0x60000134c150, name = "6")
Deconstructed:  Test(0x60000134c160, name = "7")
Deconstructed:  Test(0x60000134c170, name = "8")
Deconstructed:  Test(0x60000134c180, name = "9")
0  number of elements
*/
