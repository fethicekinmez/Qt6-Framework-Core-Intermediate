#include <QCoreApplication>
#include "test.h"

Test* makeTree(){
    Test* root = new Test(nullptr, "Root");

    for(int i=0; i<5; i++){
        Test* parentObj = new Test(root, "Parent-" + QString::number(i));
        for(int j=0; j<3; j++){
            Test* childObj = new Test(parentObj, "Child-" + QString::number(j));
            Q_UNUSED(childObj);
        }
    }

    return root;
}

void printTree(Test* root, int level=0){

    if(root->children().length() == 0) return;

    QString lead = "-";
    lead.fill('-', level * 5);

    foreach (QObject* obj, root->children()) {
        Test* child = qobject_cast<Test*>(obj);
        if(!child) return;
        qInfo() << lead << child;
        printTree(child, level+1);
    }

}

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    Test* tree = makeTree();
    printTree(tree);

    return a.exec();
}

/*

"Root"  is constructed.
"Parent-0"  is constructed.
"Child-0"  is constructed.
"Child-1"  is constructed.
"Child-2"  is constructed.
"Parent-1"  is constructed.
"Child-0"  is constructed.
"Child-1"  is constructed.
"Child-2"  is constructed.
"Parent-2"  is constructed.
"Child-0"  is constructed.
"Child-1"  is constructed.
"Child-2"  is constructed.
"Parent-3"  is constructed.
"Child-0"  is constructed.
"Child-1"  is constructed.
"Child-2"  is constructed.
"Parent-4"  is constructed.
"Child-0"  is constructed.
"Child-1"  is constructed.
"Child-2"  is constructed.
"" Test(0x600000490410, name = "Parent-0")
"-----" Test(0x600000490420, name = "Child-0")
"-----" Test(0x600000490430, name = "Child-1")
"-----" Test(0x600000490440, name = "Child-2")
"" Test(0x600000490450, name = "Parent-1")
"-----" Test(0x600000490460, name = "Child-0")
"-----" Test(0x600000490470, name = "Child-1")
"-----" Test(0x600000490480, name = "Child-2")
"" Test(0x600000490490, name = "Parent-2")
"-----" Test(0x6000004904a0, name = "Child-0")
"-----" Test(0x6000004904b0, name = "Child-1")
"-----" Test(0x6000004904c0, name = "Child-2")
"" Test(0x6000004904d0, name = "Parent-3")
"-----" Test(0x6000004904e0, name = "Child-0")
"-----" Test(0x6000004904f0, name = "Child-1")
"-----" Test(0x600000490500, name = "Child-2")
"" Test(0x600000490510, name = "Parent-4")
"-----" Test(0x600000490520, name = "Child-0")
"-----" Test(0x600000490530, name = "Child-1")
"-----" Test(0x600000490540, name = "Child-2")

 */
