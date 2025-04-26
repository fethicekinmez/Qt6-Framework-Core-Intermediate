#include "test.h"

Test::Test(QObject *parent) : QObject{parent}{
    qInfo() << this << " is constructed";

}

void Test::testing(){
    QString noise = "WAKE UP!!!";
    emit alarm(noise);
}

Test::~Test(){
    qInfo() << this << " is deconstructed";

}

void Test::wake(QString noise){
    qInfo() << "From " <<  sender() << " Noise: " << noise;
}
