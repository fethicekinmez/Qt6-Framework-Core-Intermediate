#include <QCoreApplication>
#include <QString>
#include <QStringView>
#include <QDebug>

void display(QStringView &view){

    qInfo() << view;  // "Hello world how are you today?"
    qInfo() << "Size" << view.size(); // Size 30
    qInfo() << "Data" << view.constData(); // Data 0x600003b20420
    qInfo() << "Slice" << view.sliced(3,6); // Slice "lo wor"
    qInfo() << "Contains" << view.contains(QString("ello")); // Contains true
    qInfo() << "Count" << view.count('l'); // Count 3
    qInfo() << "At" << view.at(1); // At 'e'
    qInfo() << "Index" << view[0]; // Index 'H'
    qInfo() << "Indexof" << view.indexOf('e'); // Indexof 1

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = "Hello world how are you today?";

    QStringView view(data);
    display(view);

    return a.exec();
}

