#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QRandomGenerator>

void fillRandom(QList<int> *list, int max){
    list->reserve(max);
    for(int i=0; i<max; i++){
        int number = QRandomGenerator::global()->bounded(100);
        list->append(number);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list1;
    fillRandom(&list1, 10);
    QList<int> list2;

    qInfo() << list1;
    qInfo() << list2;
    qInfo() << "Copying...";

    list2.resize(list1.size());
    std::copy(list1.begin(), list1.end(), list2.begin());
    qInfo() << list1;
    qInfo() << list2;

    return a.exec();
}

/*
QList(93, 39, 85, 84, 53, 87, 58, 62, 38, 55)
QList()
Copying...
QList(93, 39, 85, 84, 53, 87, 58, 62, 38, 55)
QList(93, 39, 85, 84, 53, 87, 58, 62, 38, 55)
 */
