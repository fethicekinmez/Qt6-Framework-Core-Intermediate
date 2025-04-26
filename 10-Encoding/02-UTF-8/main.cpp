#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRandomGenerator>


QString makeData(){

    QString data;
    data.append("Unicode test123..!!\r\n");

    for(int i=0; i<10; i++){
        int number = QRandomGenerator::global()->bounded(11120);
        data.append(QChar(number));
    }
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();
    qInfo() << "UTF-8: " << data;
    qInfo() << "ASCII: " << data.toLatin1();

    QFile File("data.txt");
    if(File.open(QIODevice::WriteOnly)){

        QTextStream stream(&File);
        stream.setEncoding(QStringConverter::Encoding::Utf8);
        stream << data;
        stream.flush();

        File.close();
        qDebug() << "File is writtren: " << File.fileName();
    }

    return a.exec();
}
