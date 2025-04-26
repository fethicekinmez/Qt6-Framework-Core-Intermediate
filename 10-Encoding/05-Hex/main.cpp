#include <QCoreApplication>
#include <QDebug>

QString makeData(){
    QString data;

    for(int i=0; i<10; i++){
        data.append("Hello\r\n");
    }

    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();
    QByteArray bytes(data.toUtf8());
    QByteArray encoded = bytes.toHex();
    QByteArray decoded = QByteArray::fromHex(encoded);

    qInfo() << "Encoded: " << encoded;
    qInfo() << "--------------------";
    qInfo() << "Decoded: " << decoded;

    return a.exec();
}

/*
Encoded:  "48656c6c6f0d0a48656c6c6f0d0a48656c6c6f0d0a48656c6c6f0d0a48656c6c6f0d0a48656c6c6f0d0a48656c6c6f0d0a48656c6c6f0d0a48656c6c6f0d0a48656c6c6f0d0a"
--------------------
Decoded:  "Hello\r\nHello\r\nHello\r\nHello\r\nHello\r\nHello\r\nHello\r\nHello\r\nHello\r\nHello\r\n"
 */
