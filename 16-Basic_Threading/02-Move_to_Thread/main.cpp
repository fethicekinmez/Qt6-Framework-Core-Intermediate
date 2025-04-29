#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QScopedPointer>
#include "task.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    QThread thread_02;
    thread_02.setObjectName("Worker Thread");

    qInfo() << "Starting: " << QThread::currentThread();

    QScopedPointer<Task> task(new Task());
    Task *task2 = task.data();
    task2->moveToThread(&thread_02);

    QObject::connect(&thread_02, &QThread::started, task2, &Task::work);
    thread_02.start();

    qInfo() << "Do other things....." << QThread::currentThread();

    return a.exec();
}
/*

Starting:  QThread(0x600000cb0260, name = "Main Thread")
Task(0x600000cb0340)  is constructed on  QThread(0x600000cb0260, name = "Main Thread")
Do other things..... QThread(0x600000cb0260, name = "Main Thread")
Start:  QThread(0x16b14af30, name = "Worker Thread")
0  on  QThread(0x16b14af30, name = "Worker Thread")
1  on  QThread(0x16b14af30, name = "Worker Thread")
2  on  QThread(0x16b14af30, name = "Worker Thread")
3  on  QThread(0x16b14af30, name = "Worker Thread")
4  on  QThread(0x16b14af30, name = "Worker Thread")
5  on  QThread(0x16b14af30, name = "Worker Thread")
6  on  QThread(0x16b14af30, name = "Worker Thread")
7  on  QThread(0x16b14af30, name = "Worker Thread")
8  on  QThread(0x16b14af30, name = "Worker Thread")
9  on  QThread(0x16b14af30, name = "Worker Thread")
Finish QThread(0x16b14af30, name = "Worker Thread")

 */

