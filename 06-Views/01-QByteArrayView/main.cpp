#include <QCoreApplication>
#include <QDebug>

void display(QByteArrayView &view){

    qInfo() << view;                                    // "Hello World"
    qInfo() << "Size" << view.size();              // Size 11
    qInfo() << "Data" << view.constData();             // Data Hello World
    qInfo() << "Slice" << view.sliced(3,6);        // Slice "lo Wor"
    qInfo() << "Contains" << view.contains("ello");    // Contains true
    qInfo() << "At" << view.at(1);                 // At e
    qInfo() << "Index" << view[0];                     // Index H
    qInfo() << "Indexof" << view.indexOf('e');     // Indexof 1
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray bytes = "Hello World";

    QByteArrayView view(bytes);

    display(view);


    return a.exec();
}
