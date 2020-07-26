#include <iostream>
#include <QtWidgets/QApplication>

#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication app(argc, argv);

    QVector <QVector <QVector <int> > > vec;

    int KT[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };

    QVector <QVector <int> > matrix;

    for(int i = 0; i < 4; i++)
    {
        QVector<int> tempVector;

        for(int j = 0; j < 4; j++)
        {
            tempVector.push_back(KT[i][j]);
            qDebug() << "Value " << j << ": " << tempVector.value(j);
        }
        matrix.push_back(tempVector);
        qDebug() << "matrix row " << i << ": " << matrix.value(i);
    }

    vec.push_back(matrix);

    qDebug() << "myVector: " << vec;

    /*
    QVector<int> vec;

    int l[10];

    int i, N=9;


    for (i=0; i<=N; i++)
{
    l[i]=i*3+1;
}


    for (i=0; i<=N; i++)
{
    vec.push_back(l[i]);
}

    qDebug()<<vec;

    int *KT=vec.data();

    for (i=0; i<=N; i++)
{
    KT[i]=KT[i]*2;
}


    qDebug()<<" ";
    qDebug()<<vec;

    */

    return app.exec();
}
