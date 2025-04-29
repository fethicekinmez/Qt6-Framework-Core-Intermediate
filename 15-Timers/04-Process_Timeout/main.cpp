#include <QCoreApplication>
#include <QProcess>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess process;
    process.start("git");

    QTimer::singleShot(4000, &process, &QProcess::terminate);


    return a.exec();
}
