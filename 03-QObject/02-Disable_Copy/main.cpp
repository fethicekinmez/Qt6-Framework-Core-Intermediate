#include <QCoreApplication>
#include <QDebug>

void testPointer(QObject* obj){
    qInfo() << obj;
}

void testReferance(QObject& obj){
    qInfo() << &obj;
}

void testCopy(QObject obj){
    qInfo() << &obj;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject person;
    person.setObjectName("Fethi");

    testPointer(&person);  // QObject(0x16cef6fa0, name = "Fethi")
    testReferance(person); // QObject(0x16cef6fa0, name = "Fethi")

    //  testCopy(person);

    return a.exec();
}

