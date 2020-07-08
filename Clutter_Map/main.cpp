#include <iostream>
#include <QtWidgets/QApplication>

#include <QDebug>

using namespace std;

int main(int argc, char *argv[]) {

    QCoreApplication app(argc, argv);
    QVector<int> vec;

    int i;
    float r,f,q;

for (i=1; i<=3; i++)
{
    vec.push_back(10); // добавляем в конец вектора элемент
    vec.push_back(15);
    vec.push_back(20);
}
    qDebug() << vec;

    return app.exec();
}
