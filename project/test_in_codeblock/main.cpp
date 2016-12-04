/*project test in code block*/
#include <iostream>
#include "../../algorithm/algorithm.h"

using namespace std;
int main()
{
    using namespace Algorithm;
    Sort<int> s;
    int a[]={12,15,78,96,53,47,19,44};
    s.print(cout,a,8);
    //s.selectsort(a,8,);
    //s.bubblesort(a,8);
    //s.insertsort(a,8,1);
    s.quicksort(a,0,7);
    s.print(cout,a,8);
    return 0;
}
