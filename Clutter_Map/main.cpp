#include <iostream>
#include <QtWidgets/QApplication>

#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication app(argc, argv);

    QVector<int> vec;

    int i, a=0, N=10;

    int *KT=vec.data();

    for (i=0; i<=N; i++)
{
    cout << KT[i];
    if (i>0)
    {
    KT[i-1]=KT[i-1]*10;
    }
}

    qDebug()<<vec;

    return app.exec();
}
