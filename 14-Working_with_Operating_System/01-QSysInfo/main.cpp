#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSysInfo sys;

    qInfo() << "System Info";
    qInfo() << "Boot Id: " << sys.bootUniqueId();
    qInfo() << "Build: " << sys.buildAbi();
    qInfo() << "Cpu: " << sys.buildCpuArchitecture();
    qInfo() << "Kernel: " << sys.kernelType();
    qInfo() << "Version: " << sys.kernelVersion();

    //Qt 5 (in Qt 6 replaced by productVersion)
    //qInfo() << "Mac: " << sys.macVersion();
    //qInfo() << "Windows: " << sys.windowsVersion();

    qInfo() << "Host: " << sys.machineHostName();
    qInfo() << "Product: " << sys.prettyProductName();
    qInfo() << "Type: " << sys.productType();
    qInfo() << "Version: " << sys.productVersion();


#ifdef Q_OS_LINUX
    qInfo() << "Linux code here";
#elif defined(Q_OS_WIN)
    qInfo() << "Windows code here";
#elif defined(Q_OS_MACX)
    qInfo() << "Mac code here";
#else
    qInfo() << "Unknown OS code here";
#endif


    return a.exec();
}


/*

System Info
Boot Id:  "22BD0B1C-34E6-4BA2-9623-6EE22F072823"
Build:  "arm64-little_endian-lp64"
Cpu:  "arm64"
Kernel:  "darwin"
Version:  "24.4.0"
Host:  "MacBookPro.home"
Product:  "macOS Sequoia (15.4)"
Type:  "macos"
Version:  "15.4"
Mac code here

*/
