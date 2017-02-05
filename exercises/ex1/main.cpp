#include <iostream>
#include "source_code/boxx.h"
#include "source_code/string_calculator.h"

using namespace std;

int main()
{
    using namespace Object;
    BOXX b1(1,2,3);
    BOXX b2(1,true);
    cout<<b1.box_volume()<<"|||"<<b1.box_area()<<"\n";
    return 0;
}
