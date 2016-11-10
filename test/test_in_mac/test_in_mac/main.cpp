//
//  main.cpp
//  test_in_mac
//
//  Created by KevinLiu on 16/11/10.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
#include "Place.h"
#include "basicPlaces.h"
#include "commonMethods.h"
using namespace std;

typedef unsigned long UINT;

UINT City::_City_num=0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void printInfo(const Place &site);//dynamic binding
bool InitCityList(City &acity);
bool ReadListFiletoCity(City cities[],const int num);

int main(int argc, const char * argv[]) {
    //city group
    const UINT citynum=4;
    City* pcities= new City[citynum];
    ReadListFiletoCity(pcities,citynum);
    Ranking cityrank;
    for(int i=0;i<citynum;++i)
    {
        cityrank.push_city(pcities[i]);
    }
    UINT z=0,c=citynum;
    cityrank.printRankedCity_x(z, c);
    cityrank.sort_city_by_population(true);
    
    string acity("Xianyang");
    cityrank.print_a_cityinfo(acity);
    
    //sort city by population via STL::map
    //cityrank.sort_city_by_population(true);
    //cout<<"\nAfter the sort"<<endl;
    //cityrank.printRankedCity_x(z, c);
    
    delete[] pcities;
    system("pause");
    return 0;
}
