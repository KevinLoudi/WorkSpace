//
//  main.cpp
//  test_in_xcode
//
//  Created by KevinLiu on 16/11/10.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
#include "commonMethods.h"
#include "Place.h"
#include "basicPlaces.h"
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
    //ReadListFiletoCity(pcities,citynum);
    
    delete[] pcities;
    system("pause");
    return 0;
}
