#include <QCoreApplication>
#include <QTimer>
#include <QDebug>

void test(){
    qInfo() << "Thanks for waiting:)";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Please wait 5 sec...";
    QTimer::singleShot(5000, &test);
    qInfo() << "This is the Main Thread";

    return a.exec();
}
