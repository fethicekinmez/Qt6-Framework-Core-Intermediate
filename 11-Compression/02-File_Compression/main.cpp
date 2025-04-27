#include <QCoreApplication>
#include <QFile>
#include <QDebug>

bool makeFile(QString path){
    QFile file(path);
    if(file.open(QIODevice::WriteOnly)){
        QByteArray data;
        for(int i=0; i<1000; i++){
            data.append(QString::number(i).toUtf8() + "\r\n");
        }
        file.write(data);
        file.close();
        return true;
    }

    return false;
}

QByteArray getHeader(){
    QByteArray header;
    header.append("@!~!@");
    return header;
}

bool compressFile(QString originalFilename, QString newFilename){
    QFile oFile(originalFilename);
    QFile nFile(newFilename);
    QByteArray header = getHeader();

    if(!oFile.open(QIODevice::ReadOnly)) return false;
    if(!nFile.open(QIODevice::WriteOnly)) return false;

    int size = 1024;

    while(!oFile.atEnd()){
        QByteArray buffer = oFile.read(size);
        QByteArray compressed = qCompress(buffer, 9);
        nFile.write(header);
        nFile.write(compressed);
    }

    oFile.close();
    nFile.close();

    qInfo() << "Compressed";

    return true;
}


bool decompressFile(QString originalFilename, QString newFilename){
    QFile oFile(originalFilename);
    QFile nFile(newFilename);
    QByteArray header = getHeader();
    int size = 1024;

    if(!oFile.open(QIODevice::ReadOnly)) return false;
    if(!nFile.open(QIODevice::WriteOnly)) return false;

    QByteArray buffer = oFile.peek(size);
    if(!buffer.startsWith(header)){
        oFile.close();
        nFile.close();
        qCritical("Did not created the file");
        return false;
    }

    oFile.seek(header.length());

    while(!oFile.atEnd()){
        buffer = oFile.peek(size);
        qint64 index = buffer.indexOf(header);
        qDebug() << "Head found at " << index;

        if(index > -1){
            qint64 maxbytes = index;
            qInfo() << "Reading: " << maxbytes;
            buffer = oFile.read(maxbytes);
            oFile.read(header.length());
        }
        else{
            qInfo() << "Read all no header";
            buffer = oFile.readAll();
        }

        QByteArray decompressed = qUncompress(buffer);
        nFile.write(decompressed);
        nFile.flush();
    }

    oFile.close();
    nFile.close();

    qInfo() << "Decompressed";

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString originalFile = "original.txt";
    QString compressedFile = "compressed.txt";
    QString decompressedFile = "decompressed.txt";

    if(makeFile(originalFile)){
        qInfo() << "Original file is created";
        if(compressFile(originalFile, compressedFile)){
            qInfo() << "File is compressed";
            if(decompressFile(compressedFile, decompressedFile)){
                qInfo() << "File is decompressed";
            }
            else{
                qInfo() << "File could not decompressed";
            }
        }
        else{
            qInfo() << "File coul not be compressed";
        }
    }
    else{
        qInfo() << "Original file could not be created";
    }

    return a.exec();
}
