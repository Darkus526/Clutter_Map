#include <iostream>
#include <QtWidgets/QApplication>
#include <cstdlib>
#include <cmath>
#include <QDebug>

using namespace std;

double okr (double value)
{
    return value=round(value*100)/100;
}

int main(int argc, char **argv)
{

    QCoreApplication app(argc, argv);

    QVector <QVector <QVector <int> > > vec;

    int KT[5][3] = { {1, 2, 3}, {5, 6, 7}, {9, 10, 11}, {13, 14, 15}, {17, 18, 19} };

    QVector <QVector <int> > matrix;

    for(int i = 0; i < 5; i++)
    {
        QVector<int> tempVector;

        for(int j = 0; j < 3; j++)
        {
            tempVector.push_back(KT[i][j]);
            qDebug() << "Value " << j << ": " << tempVector.value(j);
        }
        matrix.push_back(tempVector);
        qDebug() << "matrix row " << i << ": " << matrix.value(i);
    }

    vec.push_back(matrix);

    qDebug() << " ";
    qDebug() << vec;



    /*
    double K;

    K=okr(0.567894);

    qDebug()<<K;
    */

    return app.exec();
}
