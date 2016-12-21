/*author: Kevin  Date: 2016.12.21
   Propose: string operations in standard C
   */
#ifndef C_STD_STRING_H_INCLUDED
#define C_STD_STRING_H_INCLUDED

/**specify the standard C compiler */
#if defined(__STDC__)
# define C89
# if defined(__STDC_VERSION__)
#  define C90
#  if (__STDC_VERSION__ >= 199409L)
#   define C94
#  endif
#  if (__STDC_VERSION__ >= 199901L)
#   define C99
#  endif
# endif
#endif

#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef unsigned int UINT;

/**get length of a string */
UINT strlen_(const char*);
/**joint two string */
void strcat_(char*, const char*);
/**joint two string with a count  */
void strncat_(char*, const char*, const UINT);
/**fill string with element c */
char* strset_(char*, char );
/**fill string with cnt elements c  */
char* strnset_(char*, char, UINT);
/**compare two string within time O(1) and constant space */
int strcmp_(const char*, const char*);
/**search substring and return the position,
  -2: illegal string length
  -1: no found
   [0, (str_len-sub_len)]: first matching position*/
int strstr_(const char*, const char*);
/**reverse a string */
char* strrev_(char*);

char* strrev_(char* pStr)
{
    assert(pStr!=NULL);

    char* head=pStr;
    char* tail=pStr;
    char tmp;

    while(*tail!='\0') ++tail; //move to the end

    //do switch
    for(--tail; head<tail; ++head, --tail)
    {
        tmp=*head;
        *head=*tail;
        *tail=tmp;
    }
    return pStr;
}

int strstr_(const char* pStr, const char* pSubstr)
{
    //with assertion implemented
    UINT str_len=strlen_(pStr);
    UINT sub_len=strlen_(pSubstr);

    if(str_len<sub_len) return -2; //illegal input
    UINT tail_len=str_len-sub_len; //the longest possible remain searching scope

    UINT i,j; //for loop initial declaration is only enabled in c99 and c11
    for(i=0; i<=tail_len; ++i) //move pstr
    {
        for(j=0; j<sub_len; ++j) //move psubstr
        {
            //if not match, skip this round and start searching from the start of
            if(pStr[i+j]!=pSubstr[j])
                break;
        }
        if(j==sub_len)
            return i; //return position
    }
    //not found
    return -1;
}

int strcmp_(const char* str1, const char* str2)
{
    while((*str1!='\0')&&(*str2!='\0')&&(*str1==*str2))
        ++str1, ++str2;
    //return the difference between two string
    return (*str1-*str2);
}

char* strnset_(char* str, char c, UINT cnt)
{
    assert(str != NULL);
    char* s=str;
    for(; (*s != '\0')&&((s-str)<cnt); ++s)
        *s=c;
    return str;
}

char* strset_(char* str, char c)
{
    assert(str != NULL);
    char *s = str;
    for(; *s != '\0'; ++s)
        *s = c;
    return str;
}

void strncat_(char *pStr1, const char *pStr2, const UINT cnt)
{
  assert((pStr1!=NULL)&&(pStr2!=NULL)&&(cnt<=strlen_(pStr2)));

  //move pStr1 to its end
   while(*pStr1)
      pStr1++;

   //copy first cnt elements of str2 to str1
   UINT tmp_cnt=cnt;
   while(tmp_cnt)
   {
      *pStr1 = *pStr2;
      ++pStr2;
      ++pStr1;
      --tmp_cnt;
   }

    //add an end for str2
   *pStr1 = '\0';

}

void strcat_(char *pStr1, const char *pStr2)
{
  assert((pStr1!=NULL)&&(pStr2!=NULL));

   //move pStr1 to its end
   while(*pStr1)
      pStr1++;

   //copy str2 to str1
   while(*pStr2)
   {
      *pStr1 = *pStr2;
      pStr2++;
      pStr1++;
   }

   //add an end for str2
   *pStr1 = '\0';
}

UINT strlen_(const char* pStr)
{
    UINT ilen=0;
    if(pStr==NULL) return ilen;
    assert(pStr!=NULL);
    while(*pStr++)
    {
        ++ilen;
    }
    return ilen;
}




#endif // C_STD_STRING_H_INCLUDED
