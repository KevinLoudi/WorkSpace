/*author: Kevin  Date: 2016.12.21
   Propose: string operations in standard C
   */
#ifndef C_STD_STRING_H_INCLUDED
#define C_STD_STRING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#define bool int
#define true 1
#define false 0
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
/**string-based calculator */
int strtoint_(const char*); //atoi(const char *str)
char* inttostr_(const int); //iota
/*allocate memory*/
//void* is a special pointer with no type, and can not
//sizeof(), any pointer can assign value to void* without
//cast
void* memcre_(size_t);
/*fill a region of memory with given value of c*/
void* memset_(void*, const char , size_t);
/*copy one area of memory to another*/
void* memcpy_(void*, const void*, size_t);
/*copy one area of memory to another (in overlapping areas)*/
void* memmove_(void*, const void*, size_t);
/*release allocated memory*/
void memrel_(void*, size_t);
/*is the string a palindrome*/
bool is_palindrome_(char* str);
/*insert sort for char* string*/
void insert_sort_(char* str, const size_t n);

void insert_sort_(char* str, const size_t n)
{
  char key;
  UINT j=1; //the first element considered sorted
  for(;j<n-1;++j)
  {
    key=str[j]; //select a key
    UINT i=j-1; //search in the current unsorted region
    for(; i>0&&str[i]>key;--i)
    {
      //move backward if the current element
      //is greater than the key
      str[i+1]=str[i];
    }
    //put the key in the right place
    str[i+1]=key;
  }
}

bool is_palindrome_(char* str)
{
  if(str==NULL) return false;
  if(strlen_(str)==1) return true;

  char* head=str;
  //remember '\0' remained at the last
  char* tail=str+strlen_(str)-1;

  while(*head==*tail && head<tail)
    head++, tail--;

  if(head<tail) return false; //at least one head-tail do not match
  return true; //all head-tail pairs matched
}

void* memmove_(void* dest, const void* src, size_t count)
{
  char* d;
  const char* s;

  if(dest<=src)
  {
    d=(char*)dest;
    s=(char*)src;
    while(count--)
      *d++=*s++; //move contents
  }
  else
  {
    d=(char*)dest;
    d+=count;
    s=(char*)src;
    s+=count;
    while(count--)
      *--d=*--s;
  }
  return dest;
}

void memrel_(void* src, size_t count)
{
  if(src==NULL) return;
  free(src);
  src=NULL; //prevent the illegal use after deleted
  return;
}

void* memcre_(size_t count)
{
  void* tmp=(void*)malloc(count*sizeof(char));
  if(tmp==NULL) //fail to malloc memory
    exit(1);
  return tmp;
}

void* memcpy_(void* dest, const void* src, size_t count)
{
  char* tmp=(char*)dest;
  const char* s=(char*)src;

  while(count--)
    *tmp++=*s++;
  return dest;
}

void* memset_(void* s, const char c, size_t count)
{
  char *xs=(char*)s;
  while(count--)
    *xs++=c;
  *--xs='\0'; //add an end flag at the string-end
  return s;
}

char* inttostr_(const int num)
{
    int tmp_num=num;
    //avoid ambiguous calling through cast, C
	  const int n=(int)(log10((double)(num)+1)); //get digital bits
    //memory leakage
    char* num_str=(char*)malloc(n*sizeof(char)); //allocate memory
    if(num_str==NULL)
      exit(1);
    int i;
    for(i=0; i<n; ++i, tmp_num/=10)
    {
        num_str[i]=tmp_num%10+'0';
    }
    num_str[n]='\0';
    #ifdef DEBUG
      printf("%s%s", "converted string: ", num_str);
    #endif // DEBUG
    return num_str;
}

int strtoint_(const char* pstrnum)
{
    assert(pstrnum!=NULL);
    long long num=0;
    const long long max_num=999999999;
    bool minus=false;

    const char* digit=pstrnum;
    //const UINT num_len=strlen_(pstrnum); //get the length of the input string
    //if the sign presence, move backward, else do nothing
    if(*digit=='-')
    {
        minus=true;
        ++digit;
    }
    else if(*digit=='+')
    {
        ++digit;
    }
    else;

    while(*digit!='\0')
    {
        assert(*digit>='0' && *digit<='9'); //prevent illegal input
        num=num*10+(*digit-'0'); //conduct carry

        //overflow
        if(num>=max_num)
        {
            perror("calculation overflow!!!");
            return (int)(num);
        }

        ++digit;
    }

    return minus==true?(int)(-1*num):(int)(num);
}

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
    for(; (*s != '\0')&&((s-str) < (int)cnt); ++s)
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
