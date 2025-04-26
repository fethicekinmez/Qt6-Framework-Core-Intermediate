#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QRandomGenerator>
#include <QTextStream>

QString makeData(){

    QString data;
    data.append("UnicodeTest123!!\r\n");
    for(int i=0; i<10; i++){
        int number = QRandomGenerator::global()->bounded(10000);
        data.append(QChar(number));
    }
    data.append("\r\n");

    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();
    QFile File("data.txt");
    if(File.open(QIODevice::WriteOnly)){
        QTextStream stream(&File);
        stream.setEncoding(QStringConverter::Encoding::Utf16);
        stream << data;
        stream.flush();

        File.close();
    }

    qInfo() << "UTF-16: " << data;
    qInfo() << "UTF-8: " << data.toUtf8();
    qInfo() << "ASCII:  " << data.toLatin1();

    return a.exec();
}
