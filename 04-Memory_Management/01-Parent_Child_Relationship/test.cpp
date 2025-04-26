#include "test.h"

Test::Test(QObject *parent, QString name) : QObject{parent}{
    setObjectName(name);
    qInfo() << this->objectName() << " is constructed.";
}

Test::~Test(){
    qInfo() << "Deconstructed.";
}
