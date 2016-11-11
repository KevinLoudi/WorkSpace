#ifndef BASIC_MODEL_H
#define BASIC_MODEL_H

#include <list>
#include <iostream>
using namespace std;

class Method
{
  private:
  	list<int> _num;
  	list<string> _name;
  protected:


  public:
  	Method();
  	virtual ~Method();
};



#endif
