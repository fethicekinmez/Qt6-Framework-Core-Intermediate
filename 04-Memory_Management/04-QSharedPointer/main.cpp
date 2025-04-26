#include <QCoreApplication>
#include "test.h"
#include <QDebug>
#include <QSharedPointer>

QSharedPointer<Test> getObj(){

    QSharedPointer<Test> sp(new Test());
    sp->setObjectName("Test");
    return sp;
}

void doSomething(QSharedPointer<Test> sp){
    sp->setObjectName("Test is done");
}

void test(){
    QSharedPointer<Test> ptr = getObj();

    doSomething(ptr);
}

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    test();


    return a.exec();
}


/*

Test(0x600000fa8070) is constructed
Test(0x600000fa8070, name = "Test is done") is deconstructed

*/
