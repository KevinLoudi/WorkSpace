#include "c_string_operations.h"

namespace DataStructure
{
    const UINT Sstring::max_length=255;

    Sstring::Sstring():data(NULL),length(0)
    {

    }

    Sstring::Sstring(const char* str)
    {
     if(!str) data=NULL;
     else
     {
         length=strlen_(str); //set length
         strcpy_(data,str); //copy char elements
     }
    }

     Sstring::Sstring(const Sstring & other_string)
     {
         if(this==&other_string) return;
         this->length=strlen_(other_string.data);
         strcpy_(this->data,other_string.data);
     }

     Sstring::~Sstring()
     {

     }

     Sstring& Sstring::operator=(const Sstring& other)
     {
         if(this==&other) return *this;

         delete[] data;
         if(!other.data) this->data=NULL;
         else
         {
             this->data=new char[strlen_(other.data)+1];
             strcpy_(this->data, other.data);
         }

         return *this;
     }

      Sstring& Sstring::operator=(const char* other)
      {
          delete[] data;
          if(!other) this->data=NULL;
          else
          {
              this->data=new char[strlen_(other)+1];
              strcpy_(this->data, other);
          }

          return *this;
      }

     Sstring Sstring::operator+(const Sstring& other) const
     {
         if(!other.data) return *this;
         //will it cause problem when this and other share the same memory location
         strcpy_(this->data,other.data);
         return *this;
     }

     UINT Sstring::strlen_(const char* str) const
     {
        UINT count_=0;
        while(str[count_++]!='0'); //count the tail '\0'
        return count_;
     }

     bool Sstring::strcpy_(char* dst, const char* src)
     {
         if(!dst) return false; //need changes
         UINT len_dst=strlen_(dst);
         UINT len_src=strlen_(src);
         if(len_dst<len_src)
         {
             dst[0]='0';
             delete dst;
             dst=new char(len_src);
         }
        for(UINT i=0; i<len_src-1;++i)
        {
            dst[i]=src[i];
        }
        dst[len_src]='0';
        return  true;
     }

     std::ostream & operator<<(std::ostream & ros, Sstring& str)
     {
         ros<<str.data;
         return ros;
     }

     std::istream & operator>>(std::istream & rin, Sstring& str)
     {
         char buff[Sstring::max_length];
         rin>>std::setw(Sstring::max_length)>>buff;
         //str.Sstring::strcpy_(buff);
         return rin;
     }

};
