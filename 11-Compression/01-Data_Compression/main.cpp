#include <QCoreApplication>
#include <QDebug>

void display(QString title, QByteArray &bytes){
    qInfo() << "--------" << title << "---------";
    qInfo() << "Length: " << bytes.size();
    qInfo() << "Plain: " << bytes;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");

    QByteArray compressed = qCompress(data);
    QByteArray decompressed = qUncompress(compressed);

    display("Original", data);
    display("Compressed", compressed);
    display("Decompressed", decompressed);

    return a.exec();
}
