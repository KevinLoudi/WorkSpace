#include "../../common/cGobalDefine.h"

int main()
{
    using namespace std;
    typedef FrameWork::City City_;
    typedef FrameWork::Kingdom Kingdom_;
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

    cout<<Yan.info(cout)<<Zhao.info(cout)<<Wei.info(cout);
    return 0;
}

