#include <iostream>
#include <QtWidgets/QApplication>
#include <cstdlib>
#include <cmath>
#include <QDebug>
#include <math.h>
#include <unistd.h>

using namespace std;

class Imitator
{
    float RastMin=0, RastMax=10, AzMin=60, AzMax=120, ZenMin=45, ZenMax=70;
    int i;

public:

    int N;

    int Otmetki (float P)
    {
        float V;

        //Вычисление объёма заданной области
        V=((AzMax-AzMin)/360)*2/3*3.14*(pow((RastMax-RastMin), 3))*(1-(cos(ZenMax-ZenMin))/2);
        cout<<"V= "<<V<<" metrov"<<endl;

        //Вычисление количества ложных помех на основе заданной плотности и расчитанного объёма
        N=round(P*V);
        cout<<endl<<"N= "<<N<<" otmetok"<<endl;

        return N;
    }

    void set_i (int val) {i=val;}

    int KT ()
    {
        int Rast, Az, Zen;

        Rast=RastMin + rand() % int(RastMax-RastMin);
        Zen=ZenMin + rand() % int(ZenMax-ZenMin);
        Az=AzMin + rand() % int(AzMax-AzMin);

        if (i=0) return Rast; else if (i=1) return Az; else return Zen;
    }

};

class Cont
{
  public:

    QVector <int*> matrix;

    void Vozvrat ()
    {

    int L;

    Imitator N{};

    L=N.Otmetki (2);

    Imitator K[3], *p;

    K[0].set_i(0);
    K[1].set_i(1);
    K[2].set_i(2);

    p=&K[0];

    for (int i=1; i<L; i++)

    {

    p->KT();
    cout<<p<<endl;
    p++;
    p->KT();
    cout<<p<<endl;

    p++;
    p->KT();
    cout<<p<<endl;

    p--;
    p--;

    }

    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    auto start = clock();
    srand( time( 0 ) );
    int* N1;

    Cont K{};

    K.Vozvrat();

    cout<<endl<<endl;


    /*
    float RastMin=0, RastMax=10, AzMin=60, AzMax=120, ZenMin=45, ZenMax=70;
    float V;
    V=((AzMax-AzMin)/360)*2/3*3.14*(pow((RastMax-RastMin), 3))*(1-(cos(ZenMax-ZenMin))/2);
    cout<<V<<endl;
    */

    /*

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
*/
}
