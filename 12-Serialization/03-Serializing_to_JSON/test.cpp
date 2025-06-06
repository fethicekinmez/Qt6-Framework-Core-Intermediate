#include "test.h"

Test::Test(QObject *parent) : QObject{parent}{

}

// Getter - Setter Name
QString Test::name(){
    return m_name;
}
void Test::setName(QString value){
    m_name = value;
}
// Getter - Setter Map
QMap<QString, QString> Test::map(){
    return  m_map;
}
void Test::setMap(QMap<QString, QString> newMap){
    m_map = newMap;
}
// filling object member variables (name and map) with test data.
void Test::fill(){
    m_name = "test object";
    for(int i = 0; i < 10; i++) {
        QString num = QString::number(i);
        QString key = "Key: " + num;
        QString value = "This is item number: " + num;
        m_map.insert(key,value);
    }
}

