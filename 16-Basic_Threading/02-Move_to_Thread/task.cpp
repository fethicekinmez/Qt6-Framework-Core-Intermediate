#include "task.h"

Task::Task(QObject *parent) : QObject{parent}{
    qInfo() << this << " is constructed on " << QThread::currentThread();
}

Task::~Task(){
    qInfo() << this << " is deconstructed on " << QThread::currentThread();
}

void Task::work()
{
    QThread *thread = QThread::currentThread();

    qInfo() << "Start: " << thread;

    for(int i=0; i<10; i++){
        qInfo() << i << " on " << thread;
    }

    qInfo() << "Finish" << thread;
}
