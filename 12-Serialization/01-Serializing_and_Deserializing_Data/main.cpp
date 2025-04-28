#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QDebug>

bool saveFile(QString path){
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly)) return false;
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_6_9);

    QString title = "Hello World";
    qint64 num = 54;

    out << title;
    out << num;

    file.close();

    return true;
}

bool readFile(QString path){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) return false;

    QDataStream in(&file);
    if(in.version() != QDataStream::Qt_6_9){
        qCritical() << "Versions do not match!";
        file.close();
        return false;
    }

    QString title;
    qint64 num;

    in >> title;
    in >> num;

    qDebug() << title;
    qDebug() << num;

    file.close();
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file = "test.txt";
    if(saveFile(file)){
        qInfo() << "File Saved";
        readFile(file);
    }

    return a.exec();
}
