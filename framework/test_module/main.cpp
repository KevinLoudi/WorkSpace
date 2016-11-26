#include "../../common/cGobalDefine.h"

typedef Gobal::PowerUniverse World_;
typedef FrameWork::City City_;
typedef FrameWork::Kingdom Kingdom_;
typedef Algorithm::Method Method_;
typedef Algorithm::Parallel Parallel_;

void BuildTest();
void ThreadTest();
void AlgorithmTest();

static int Stateix=0;
static std::vector<Kingdom_> States;

void UniverseTest();

void CountryThread();

int main()
{
    //BuildTest();
    //ThreadTest();
    AlgorithmTest();
    return 0;
}

void AlgorithmTest()
{
     using namespace std;
     //Method_ m;
    //m.DemoClassBuilding();
    //Algorithm::Base b;
    //Algorithm::Derived d;
    //Algorithm::Derived d2;
    //create a group of temporal object
    //d2=m.DemoTemporalObject(b,d);

    /*Parallel_ p1(1), p2(2), p3(3), p4(4);
    p1.start();
    p2.start();
    p3.start();
    p4.start(); */

    /*const int Num=11;
    int data[Num] = {96,33,52,56,98,12,75,45,36,45,96};
    //m.QuickSort(data,0,Num-1);
    m.ShellSort(data, Num);
    cout<<m.ArrayPrinter(data,Num,cout);*/

    namespace Alg=Algorithm;
    Alg::VirBase *pB;
    Alg::VirDerivedOne d1;
    Alg::VirDerivedTwo d2;

    pB= &d1;
    pB->eat();
    pB->sleep();

    pB= &d2;
    pB->eat();
    pB->sleep();

    Alg::VirMulDerived dd;
    pB=&dd;


}

void BuildTest()
{
     using namespace std;
    //    typedef FrameWork::Farmland Farmland_;
   //    typedef FrameWork::aPlace aPlace_;
   //    typedef Gobal::FileIO FileIO_;
    vector<City_> cities;
    //ancient Chinese cities name in dynasty of Zhou
    cities.push_back(City_(2,3,"Jian",23000)); //¼» , base of Yan, Ñà
    cities.push_back(City_(0,0,"Longchen",12000)); //Áú³Ç
    cities.push_back(City_(2,4,"Dukang",19000)); //¶½¿º

    cities.push_back(City_(4,4,"Handan",43000)); //ºªµ¦, base of Zhao ÕÔ
    cities.push_back(City_(5,6,"Jinyang",35000)); //½úÑô
    cities.push_back(City_(5,3,"Wuan",25000)); //Îä°²

    cities.push_back(City_(7,3,"Daliang",152000)); //´óÁº, base of Wei Îº
    cities.push_back(City_(5,8,"Anyi",86000)); //°²ÒØ
    cities.push_back(City_(5,9,"Puban",46000)); //ÆÑÚæ

    vector<City_>::const_iterator it_c = cities.begin();
    for(; it_c!=cities.end();it_c++)
    {
        cout<<(*it_c).info(cout);
    }

    vector<City_>::iterator it = cities.begin();
    vector<City_> yan_cities(it,it+3);
    vector<City_> zhao_cities(it+3,it+6);
    vector<City_> wei_cities(it+6,it+9);


    Kingdom_ Yan(1,"Yan","YanZhaoWang",yan_cities);
    Kingdom_ Zhao(3,"Zhao","ZhaoHuiWenWang",zhao_cities);
    Kingdom_ Wei(2,"Wei","WeiHuiWang",wei_cities);

    //cout<<Yan.info(cout)<<Zhao.info(cout)<<Wei.info(cout);

    States.push_back(Yan) ; States.push_back(Zhao) ;  States.push_back(Wei) ;
    Stateix+=3;
}
