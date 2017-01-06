#include "hash_code.h"

//默认的hashCode
int myHashCodeDefault(void * a)
{
    return (int) a;
}

//int类型hashCode
int myHashCodeInt(void * a)
{
    int * aa = (int *) a;
    return *aa;
}

//char类型的hashCode
int myHashCodeChar(void * a)
{
    char *aa = (char *) a;
    return *aa;
}

//string类型的hashCode
int myHashCodeString(void * a)
{
    int re = 0;
    char *aa = (char *) a;
    while (*aa)
    {
        re += HASHCODE_MULT * *aa;
        aa++;
    }
    return re;
}
