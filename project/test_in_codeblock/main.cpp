/*project test in code block*/
#include <iostream>
#include "../../algorithm/algorithm.h"

using namespace std;

int main()
{
    using namespace Algorithm;
    Sort<int> s;
    int a[]={12,15,78,96,53,47,19,44};
    s.selectsort<int>(a,8);
    cout << "Hello world!" << endl;
    return 0;
}
