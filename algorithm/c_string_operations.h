#ifndef C_STRING_OPERATIONS_H_INCLUDED
#define C_STRING_OPERATIONS_H_INCLUDED

#include <iostream>
#include <stdexcept>

namespace DataStructure
{
    typedef unsigned int UINT;
    class Sstring
    {
    public:
        //Initialize
        Sstring();
        Sstring(const char* str);
        Sstring(const Sstring & other_string);
        ~Sstring();
        //Get Info
        UINT strlen_(const char* str) const; //get length of char* data, include the tail '\0'
        bool strcpy_(char* dst, const char* src); //copy char* data from one c_string to another

    private:
        char* data;
        UINT length;

    };

}

#endif // C_STRING_OPERATIONS_H_INCLUDED
