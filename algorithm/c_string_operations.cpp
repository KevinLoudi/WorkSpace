#include "c_string_operations.h"

namespace DataStructure
{
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
         /*this->length=other_string.length;
         if(data[0]!='0') delete data;
         data=new char(length);
         for(UINT i=0;i<length;++i)
            data[i]=other_string.data[i];*/
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

};
