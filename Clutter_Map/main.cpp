#include <iostream>
#include <QtWidgets/QApplication>
#include <cstdlib>
#include <cmath>
#include <QDebug>
#include <math.h>

using namespace std;


int main(int argc, char **argv)
{
    setlocale(LC_ALL, "Russian");
    srand( time( 0 ) );

    QCoreApplication app(argc, argv);
    int M, N=0, N0=0, N1=0;
    const int R=10;
    float xc,yc,zc;

    cout<<"Введите число генерируемых отметок:"<<endl<<endl;
    cin>>M;

    QVector <QVector <int> > matrix;

    for(int i = 0; i < M; i++)
    {
        QVector<int> tempVector;
        tempVector.push_back(rand() % 10000);
        tempVector.push_back(rand() % 180);
        tempVector.push_back(rand() % 360);

        matrix.push_back(tempVector);
    }

    cout<<endl<<endl;

    cout<<"Введите координаты точки запроса"<<endl<<endl;
    cin>>xc>>yc>>zc;
    cout<<endl<<endl;

    xc=round(xc/100);
    yc=round(yc/100);
    zc=round(zc/100);

    for(int i=0; i<M; i++)
    {
        int x=0,y=0,z=0;
        float KT[9][4];

        x=round((matrix[i][0]*sin(matrix[i][1]*(M_PI/180))*cos(matrix[i][2]*(M_PI/180)))/100);
        y=round((matrix[i][0]*sin(matrix[i][1]*(M_PI/180))*sin(matrix[i][2]*(M_PI/180)))/100);
        z=round((matrix[i][0]*cos(matrix[i][1]*(M_PI/180)))/100);

        float rast=abs(sqrt(pow((x-xc), 2)+pow((y-yc), 2)+pow((z-zc), 2)));

        if (rast<=R)
        {
            N=N+1;
        }

        for (int i=0; i<7; i++)
        {
            KT[i][0]=x;
            KT[i][0]=y;
            KT[i][0]=z;
        }

        //Размытие одной координатной точки по Гауссу

        KT[1][0]=(x-1);
        KT[1][3]=0.75;
        KT[2][1]=(y+1);
        KT[2][3]=0.75;
        KT[3][0]=(x+1);
        KT[3][3]=0.75;
        KT[4][1]=(y-1);
        KT[4][3]=0.75;
        KT[5][0]=(x-1);
        KT[5][1]=(y+1);
        KT[5][3]=0.5;
        KT[6][0]=(x+1);
        KT[6][1]=(y+1);
        KT[6][3]=0.5;
        KT[7][0]=(x-1);
        KT[7][1]=(y-1);
        KT[7][3]=0.5;
        KT[8][0]=(x+1);
        KT[8][1]=(y-1);
        KT[8][3]=0.5;

        //Расчёт количества ложных помех в области

        for (int j=0; j<9; j++)
        {

        float rast=abs(sqrt(pow((KT[j][0]-xc), 2)+pow((KT[j][1]-yc), 2)+pow((KT[j][2]-zc), 2)));

        if (rast<=R && KT[j][3]>0.5)
        {
            N0=N0+1;
        }

        }

    }
    cout<<endl<<endl;
    cout<<"Плотность ложных помех в области " <<N0/((4/3)*M_PI*R*R*R)<<endl<<endl;

}
