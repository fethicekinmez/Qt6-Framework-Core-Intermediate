#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

    QString name();
    void setName(QString value);

    QMap<QString, QString> map();
    void setMap(QMap<QString, QString> newMap);

    void fill();

    friend QDataStream& operator <<(QDataStream &stream, const Test &t)
    {
        qInfo() << "Operator <<";
        stream << t.m_name;
        stream << t.m_map;
        return stream;
    }

    friend QDataStream& operator >>(QDataStream &stream, Test &t)
    {
        qInfo() << "Operator >>";
        stream >> t.m_name;
        stream >> t.m_map;
        return stream;
    }

signals:

private:
    QString m_name;
    QMap<QString, QString> m_map;
};

#endif // TEST_H
