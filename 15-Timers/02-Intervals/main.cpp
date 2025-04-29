#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test t;
    t.doSomething();

    return a.exec();
}

/*

"13:22:00"  :  1000
"13:22:01"  :  1000
"13:22:02"  :  1000
"13:22:03"  :  1000
"13:22:04"  :  1000
Completed

 */
