/*Implementation of  algorithms*/
#ifndef CALGORITHM_H_INCLUDED
#define CALGORITHM_H_INCLUDED

#include<iostream>
#include<pthread.h>
#include<assert.h>
//asks the compiler to include a header file only a single time, no matter how many times it has been imported
#pragma once

namespace Algorithm
{
using namespace std;
class Base
{
   private:
       int _b;
    public:
    Base() {std::cout << "  Base::Base() default constructor\n";}
    Base(const int& b): _b(b) { std::cout << "  Base::Base() constructor\n"; }
    Base(const Base& base):_b(base._b)
    {
        std::cout << "  Base::Base() copy constructor\n";
        //_b=base._b;
    }
    Base & operator=(const Base& base)
    {
        _b=base._b;
        std::cout << "  Base::Base() copy assignment\n";
        return *this;
    }
    // Note: non-virtual destructor is OK here
    ~Base() { std::cout << "  Base::~Base() destructor\n"; }
};

class Derived: public Base
{
    private:
        int _d;
    public:
    Derived() {std::cout << "  Derived::Derived() default constructor\n";}
    Derived(const int& b,const int& d):Base(b),_d(d) { std::cout << "  Derived::Derived() constructor\n"; }
    Derived(const Derived& derived):Base(derived)   //, _d(derived._d)
     {
        std::cout << "  Derived::Derived() copy constructor\n";
        *this=derived;
     }
     Derived & operator=(const Derived & derived)
     {
        std::cout << "  Derived::Derived() copy assignment\n";
        _d=derived._d;
        return *this;
     }
    ~Derived() { std::cout << "  Derived::~Derived() destructor\n"; }
};

class VirBase
{
public:
    std::string _ClassName;
    VirBase(std::string name):_ClassName(name)
     {std::cout <<"VirBase object"<< _ClassName<<"constructed"<<std::endl;}
    ~VirBase() {std::cout <<"VirBase object"<< _ClassName<<"destructed"<<std::endl;}
    virtual void sleep() = 0;
    virtual void see() = 0;
};

class VirDerivedOne: public VirBase
{
public:
    VirDerivedOne(std::string name):VirBase(name)
     {std::cout <<"VirDerivedOne object"<< _ClassName<<"constructed"<<std::endl;}
     ~VirDerivedOne()
     {std::cout <<"VirDerivedOne object"<< _ClassName<<"destructed"<<std::endl;}
    void sleep()  {std::cout <<"one sleep"<<std::endl;}
    void eat() {std::cout <<"one see"<<std::endl;}
};

class VirDerivedTwo: public VirBase
{
public:
     VirDerivedTwo(std::string name):VirBase(name)
     {std::cout <<"VirDerivedTwo object"<< _ClassName<<"constructed"<<std::endl;}
     ~VirDerivedTwo()
     {std::cout <<"VirDerivedTwo object"<< _ClassName<<"destructed"<<std::endl;}
    void sleep()  {std::cout <<"two sleep"<<std::endl;}
    void eat() {std::cout <<"two see"<<std::endl;}
};

//if I do not use virtual inheritance, error "reference ambiguous" will happen
class VirMulDerived: virtual  public VirDerivedOne,  virtual public VirDerivedTwo
{
      VirMulDerived(std::string name):VirDerivedOne(name)
     {std::cout <<"VirMulDerived object"<< _ClassName<<"constructed"<<std::endl;}
     ~VirMulDerived()
     {std::cout <<"VirMulDerived object"<< _ClassName<<"destructed"<<std::endl;}
    //life is more than sleep and eat
    void life() {VirDerivedOne::sleep(); VirDerivedTwo::eat();}
};

class Method
{

    public:
    Method() {}
    ~Method() {}
    /*demo the difference of (default) constructor, copy constructor and copy assignment*/
    void DemoClassBuilding();
    /*create some temporal object through value-pass in and return */
    Derived DemoTemporalObject(Base b, Derived d);
    /*implementation of quick sort */
    void QuickSort(int  a[], int low, int high);
    /*implementation of shell  sort*/
    void ShellSort(int a[], const int & len);
    /*print out array*/
    ostream & ArrayPrinter(const int  a[], const int & _size, ostream & ros) const;
};

class Parallel
{
private:
    pthread_t thread;
    int thread_ix;

    static void* staticEntryPoint(void * c);
    void entryPoint();
public:
    explicit Parallel(int ix=0):thread_ix(ix) {}
    ~Parallel() {}
    void start();
};

};

#endif // CALGORITHM_H_INCLUDED
