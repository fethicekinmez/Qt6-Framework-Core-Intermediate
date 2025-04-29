#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <QRandomGenerator>

void fillRandom(QList<int> *list, int max){
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
    fillRandom(&list, 10);
    qInfo() << list;

    std::sort(list.begin(),list.end());
    qInfo() << list;

    std::reverse(list.begin(), list.end());
    qInfo() << list;

    return a.exec();
}
