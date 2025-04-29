#include <QCoreApplication>
#include <QThread>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread *thread = QThread::currentThread();
    thread->setObjectName("Main Thread");

    qInfo() << "Start: " << thread;
    qInfo() << "Main Thread: " << thread->isMainThread();

    for(int i=0; i<10; i++){
        qInfo() << i << "on " << thread;
    }
    qInfo() << "Finish: " << thread;

    return a.exec();
}
