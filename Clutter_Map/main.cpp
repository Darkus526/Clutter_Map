#include <iostream>
#include <QtWidgets/QApplication>

#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication app(argc, argv);

    QVector<int> vec;

    int l[10];

    int i, a=0, N=9;


    for (i=0; i<=N; i++)
{
    l[i]=i*3+1;
}


    for (i=0; i<=N; i++)
{
    vec.push_back(l[i]);
}

    int *KT=vec.data();

    for (i=0; i<=N; i++)
{
    KT[i]=KT[i]*2;
    qDebug()<<KT[i];
}

    qDebug()<<" ";
    qDebug()<<vec;
    return app.exec();
}
