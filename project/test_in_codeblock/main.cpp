/*project test in code block*/
#include <iostream>
#include <string>
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
    LinkList<string> l;
    l.addLast("a");
    l.addLast("b");
    l.addLast("c");
    l.addFirst("0");
    cout<<l.print(cout);
    cout<<endl<<l.getFirst()<<" "<<l.getLast()<<endl;
    //make run-time error happen
    //cout<<l.removeLast()<<l.removeLast()<<l.removeLast()<<l.removeLast()<<l.removeLast();
    //cout<<l.removeLast()<<" "<<l.removeFirst()<<endl;
    l.addix("cc",2);
    cout<<"access "<<l.getix(2)<<endl;
    cout<<l.removeix(2)<<endl;
    cout<<"newest list"<<endl;
    cout<<l.print(cout);
    /*int b=23;
    int* pb=&b;
    LinkList l;
    l.addLast(b);
    l.addLast(b+10);
    l.addLast(b-10);
    cout<<l.print(cout);*/
    return 0;
}
