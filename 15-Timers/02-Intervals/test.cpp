#include "test.h"

Test::Test(QObject *parent) : QObject{parent}{

    number = 0;
    timer.setInterval(1000);
    QObject::connect(&timer, &QTimer::timeout, this, &Test::timeout);
}

void Test::timeout()
{
    number++;

    qInfo() << QTime::currentTime().toString(Qt::DateFormat::TextDate) << " : " << timer.interval();

    if(number >= 5){
        timer.stop();
        qInfo() << "Completed";
    }
}

void Test::doSomething()
{
    number = 0;
    timer.start();
}
