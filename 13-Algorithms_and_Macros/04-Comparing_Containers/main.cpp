#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QRandomGenerator>

void fillRandoms(QList<int> *list, int max){
    list->reserve(max);
    for(int i=0; i<max; i++){
        int number = QRandomGenerator::global()->bounded(1000);
        list->append(number);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    fillRandoms(&list, 10);
    qInfo() << list;

    QList<int> list2;
    fillRandoms(&list2, 10);
    qInfo() << list2;

    qInfo() << "Equal: " << std::equal(list.begin(), list.end(),list2.begin());

    list.fill(9);
    list2.fill(9);

    qInfo() << "Equal: " << std::equal(list.begin(), list.end(),list2.begin());

    return a.exec();
}

/*

QList(310, 499, 420, 368, 289, 940, 78, 918, 123, 131)
QList(485, 123, 134, 37, 695, 21, 833, 412, 938, 421)
Equal:  false
Equal:  true

*/
