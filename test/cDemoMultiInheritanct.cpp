#include<iostream>

/*static int xv=10;

class VirBase
{
public:
    std::string _ClassName;
    VirBase(std::string name="null VirBase"):_ClassName(name)
     {std::cout <<"VirBase object"<< _ClassName<<"constructed"<<std::endl;}
    virtual ~VirBase() {std::cout <<"VirBase object"<< _ClassName<<"destructed"<<std::endl;}
    virtual void sleep() {};
    virtual void see() {};
};

class VirDerivedOne:  public virtual VirBase
{
public:
    VirDerivedOne(std::string name="null VirDerivedOne"):VirBase(name)
     {std::cout <<"VirDerivedOne object"<< _ClassName<<"constructed"<<std::endl;}
     ~VirDerivedOne()
     {std::cout <<"VirDerivedOne object"<< _ClassName<<"destructed"<<std::endl;}
    virtual void sleep()  {std::cout <<"one sleep"<<std::endl;}
    virtual void eat() {std::cout <<"one see"<<std::endl;}
};

class VirDerivedTwo: public virtual VirBase
{
public:
     VirDerivedTwo(std::string name="null VirDerivedTwo"):VirBase(name)
     {std::cout <<"VirDerivedTwo object"<< _ClassName<<"constructed"<<std::endl;}
     ~VirDerivedTwo()
     {std::cout <<"VirDerivedTwo object"<< _ClassName<<"destructed"<<std::endl;}
    virtual void sleep()  {std::cout <<"two sleep"<<std::endl;}
    virtual void eat() {std::cout <<"two see"<<std::endl;}
};

//if I do not use virtual inheritance, error "reference ambiguous" will happen
class VirMulDerived: public VirDerivedOne, public VirDerivedTwo
{
public:
      VirMulDerived(std::string name="null VirDerivedTwo"): VirDerivedOne(name),VirDerivedTwo(name),
      VirBase(name)
     {std::cout <<"VirMulDerived object"<<_ClassName<<"constructed"<<std::endl;}
     ~VirMulDerived()
     {std::cout <<"VirMulDerived object"<< _ClassName<<"destructed"<<std::endl;}
    //life is more than sleep and eat
    //void life() {sleep(); }
}; */

class A
{
public:
    int x;
    A(int x):x(x){std::cout<<"A"<<std::endl;}
};

class B: public virtual A
{
public:
    B(int x):A(x){std::cout<<"B"<<std::endl;}
};
class C: public virtual A
{
public:
    C(int x):A(x){std::cout<<"C"<<std::endl;}
};
class D: public B, public C
{
public:
    D(int x):B(x++), C(x++), A(x++){std::cout<<"D"<<std::endl;}
};


int main()
{
    D d(12);
    //VirMulDerived vmd("vmd");
    return 0;
}
