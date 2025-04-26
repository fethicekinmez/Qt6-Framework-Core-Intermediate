#include "test.h"

Test::Test(QObject *parent) : QObject{parent}{
    qInfo() << this << " is constructed";
}

Test::~Test(){
    qInfo() << this << " is deconstructed";
}
