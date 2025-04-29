#include <QCoreApplication>
#include <QDebug>

//Custom macro
#define add(a,b) a+b

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << add(1,2); // 3

    qInfo() << add(false, false); // 0
    qInfo() << add(true, false); // 1
    qInfo() << add(true, true); // 2


    return a.exec();
}
