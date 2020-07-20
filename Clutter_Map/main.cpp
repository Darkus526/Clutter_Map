#include <iostream>
#include <QtWidgets/QApplication>

#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication app(argc, argv);

    QVector<int> vec;

    int i, a=0, N=10;

    for (i=0; i<N; i++)
{
    vec.push_back(i+1);
}

    int *KT=vec.data();

    for (i=0; i<N; i++)
{
    KT[i]=KT[i]*2;
}

    qDebug()<<vec;
    return app.exec();
}
