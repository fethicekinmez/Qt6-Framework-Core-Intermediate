#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>

QByteArray makeData(){
    QByteArray data;
    for(int i=0; i<10; i++){
        data.append(72);
        data.append(101);
        data.append(108);
        data.append(108);
        data.append(111);
        data.append(33);
        data.append(13);
        data.append(10);
    }
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data = makeData();
    QFile File("data.txt");
    if(File.open(QIODevice::WriteOnly)){
        File.write(data);

        File.close();
        qDebug() << "The File is written: " << File.fileName() ;
    }
    qInfo() << data;

    return a.exec();
}
