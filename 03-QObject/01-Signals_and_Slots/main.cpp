#include <QCoreApplication>
#include "test.h"

void notification(){

    Test mom;
    Test child;
    mom.setObjectName("Mom");
    child.setObjectName("Child");

    QObject::connect(&mom, &Test::alarm, &child, &Test::wake);

    mom.testing();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    notification();

    return a.exec();
}

/*
Test(0x16d35af50)  is constructed
Test(0x16d35af40)  is constructed
From  Test(0x16d35af50, name = "Mom")  Noise:  "WAKE UP!!!"
Test(0x16d35af40, name = "Child")  is deconstructed
Test(0x16d35af50, name = "Mom")  is deconstructed
*/
