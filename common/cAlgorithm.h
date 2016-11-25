/*Implementation of  algorithms*/
#ifndef CALGORITHM_H_INCLUDED
#define CALGORITHM_H_INCLUDED

#include<iostream>
#include<pthread.h>
//asks the compiler to include a header file only a single time, no matter how many times it has been imported
#pragma once

namespace Algorithm
{
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

class Method
{
    public:
    Method() {}
    ~Method() {}
    /*demo the difference of (default) constructor, copy constructor and copy assignment*/
    void DemoClassBuilding();
    /*create some temporal object through value-pass in and return */
    Derived DemoTemporalObject(Base b, Derived d);
    /* */
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
