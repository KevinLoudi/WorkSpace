/*
 Author: Kevin
 Date: 3rd Feb, 2017
 Propose: exercise day2, create a sting-defined calculator
 Environment: gcc 4.2
*/

#ifndef STRING_CALCULATOR_H_INCLUDED
#define STRING_CALCULATOR_H_INCLUDED

typedef char* LPSTR;
typedef unsigned int UINT;

namespace Tool
{
    class Calculator
    {
    public:
        Calculator(LPSTR in,LPSTR sa=zero_,LPSTR ou=zero_):input_(in),save_(sa),output_(ou){}
        ~Calculator();
        LPSTR Sum();
        LPSTR Sum(LPSTR in1, LPSTR in2);
    private:
        LPSTR input_;
        LPSTR save_;
        LPSTR output_;
        double LPSTR_to_double(LPSTR num);
    protected:
        static LPSTR zero_;
    };
}


#endif // STRING_CALCULATOR_H_INCLUDED
