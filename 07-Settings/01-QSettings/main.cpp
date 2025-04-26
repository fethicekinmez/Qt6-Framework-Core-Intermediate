#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

void info(QSettings &settings){
    qInfo() << settings.fileName();
    qInfo() << settings.allKeys();
}

void save(QSettings &settings){
    settings.setValue("test", QVariant(1234));
    qInfo() << settings.status();
    qInfo() << "saved";
}

void load(QSettings &settings){
    info(settings);
    qInfo() << settings.value("test").toString();
    qInfo() << settings.value("test").toInt();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Fethi Company");
    QCoreApplication::setOrganizationDomain("fethi");
    QCoreApplication::setApplicationName("Tester");

    qInfo() << QCoreApplication::organizationName();
    qInfo() << QCoreApplication::organizationDomain();

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    if(settings.allKeys().length() == 0){
        qInfo() << "Saving settings...";
        save(settings);
    }
    else{
        load(settings);
    }





    return a.exec();
}
