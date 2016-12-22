#ifndef C_STRING_OPERATIONS_H_INCLUDED
#define C_STRING_OPERATIONS_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include <iomanip>

namespace DataStructure
{
    typedef unsigned int UINT;
    class Sstring
    {
        //overload operator
        friend std::ostream & operator<<(std::ostream &, Sstring&);
        friend std::istream & operator>>(std::istream &, Sstring&);
    public:
        //Initialize
        Sstring();
        Sstring(const char* str);
        Sstring(const Sstring &);
        ~Sstring();
        //operator
        Sstring& operator=(const Sstring&);
        Sstring& operator=(const char*);
        Sstring operator+(const Sstring& other) const;
        bool operator==(const Sstring& other) const;
        char& operator[] (UINT);
        //Get Info
        UINT strlen_(const char* str) const; //get length of char* data, include the tail '\0'
        bool strcpy_(char* dst, const char* src); //copy char* data from one c_string to another
        size_t size() {return length;}
    private:
        char* data;
        UINT length;
        const static UINT max_length;
    };

}

#endif // C_STRING_OPERATIONS_H_INCLUDED
