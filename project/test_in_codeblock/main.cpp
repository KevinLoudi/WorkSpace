/*project test in code block*/
#include <iostream>
#include <string>
#include "../../algorithm/algorithm.h"
#include "../../algorithm/basic_data_structure.h"
#include "../../algorithm/ddlinklist.h"

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
    /*LinkList<string> l;
    l.addLast("a");
    l.addLast("b");
    l.addLast("c");
    /*l.addFirst("0");
    l.addFirst("-1");
    l.addFirst("-2");*/
    /*cout<<l.print(cout);
    cout<<endl<<l.getFirst()<<" "<<l.getLast()<<endl;
    //make run-time error happen
    //cout<<l.removeLast()<<l.removeLast()<<l.removeLast()<<l.removeLast()<<l.removeLast();
    //cout<<l.removeLast()<<" "<<l.removeFirst()<<endl;
    l.addix("cc",2);
    cout<<"access "<<l.getix(2)<<endl;
    cout<<"find "<<"cc at"<<l.searchix("cc")<<endl;
    cout<<l.removeix(2)<<endl;
    cout<<"newest list"<<endl;
    cout<<l.print(cout);
    cout<<"clear list"<<endl;
    cout<<l.clearlist();
    cout<<l.print(cout);*/

    //int ix=l.searchix("0");
    //cout<<l.print_reverse_helper(cout,ix);

    /*cout<<"Initial list: "<<endl;
    cout<<l.print(cout)<<endl;
    Node<string>* StrHead=l.getHead();
    Node<string>* StrTail=l.getTail();
    cout<<StrHead->element<<" "<<StrTail->element<<endl;
    l.reverselist();
    cout<<"Reversed list: "<<endl;
    cout<<l.print(cout)<<endl; */

    DoubleLinkList<string> dlst;
    dlst.addFirst("a");
    dlst.addFirst("b");
    dlst.addFirst("c");
    dlst.addFirst("d");
    cout<<dlst.print(cout);
    return 0;
}
