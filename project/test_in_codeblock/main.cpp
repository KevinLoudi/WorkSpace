/*project test in code block*/
#include <iostream>
#include "../../algorithm/algorithm.h"
#include "../../algorithm/basic_data_structure.h"

using namespace std;
int main()
{
    /*using namespace Algorithm;
    Sort<int> s;
    int a[]={12,15,78,96,53,47,19,44};
    s.print(cout,a,8);
    //s.selectsort(a,8,);
    //s.bubblesort(a,8);
    //s.insertsort(a,8,1);
    s.quicksort(a,0,7);
    s.print(cout,a,8); */

    using namespace DataStructure;
    int b=23;
    int* pb=&b;
    LinkList l;
    l.addLast(b);
    l.addLast(b+10);
    l.addLast(b-10);
    cout<<l.print(cout);
    return 0;
}
