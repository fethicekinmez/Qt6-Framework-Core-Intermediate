#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

bool test(){

    QProcess oText;
    oText.start("open", QStringList() << "-a spotify");

    if(!oText.waitForStarted(3000)){
        qDebug("waitForStarted: error=%d\n", oText.error());
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(test()){
        qInfo() << "Text runs..";
    }
    else{
        qInfo() << "Could Not Run..";
    }

    return a.exec();
}
