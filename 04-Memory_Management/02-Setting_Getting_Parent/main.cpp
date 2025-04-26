#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject parent;
    parent.setObjectName("Parent");

    QObject child;
    child.setObjectName("Child");

    // setting a parent
    child.setParent(&parent);

    // getting a parent
    qInfo() << "Parent of the child: " << child.parent();

    // getting the children
    qInfo() << "Children of the parent: " << parent.children();

    foreach (QObject* obj, parent.children()) {
        qInfo() << "Children: " << obj;
    }


    return a.exec();
}

/*

Parent of the child:  QObject(0x16b1caf00, name = "Parent")
Children of the parent:  QList(QObject(0x16b1caed0, name = "Child"))
Children:  QObject(0x16b1caed0, name = "Child")

 */
