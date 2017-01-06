#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define DEBUG

#include <stdio.h>

typedef struct myNode
{
    void * data;
    struct myNode *next;
} MyNode;

typedef struct myList
{
    MyNode * first;
    MyNode * last;
    int count;
    int (*equal)(void * a, void * b);
} MyList;

typedef struct myListIterator
{
    MyNode * p;
    int count;
    int allSize;
} MyListIterator;

//创建链表
MyList * createMyList();

//创建链表，带有相等参数，用于查找
MyList * createMySearchList(int(*equal)(void * a, void * b));

//释放链表
void freeMyList(MyList * list);

//插入在尾部
void myListInsertDataAtLast(MyList* const list, void* const data);

//插入在首部
void myListInsertDataAtFirst(MyList * const list, void* const data);

//插入
void myListInsertDataAt(MyList * const list, void* const data, int index);

//删除在尾部
void* myListRemoveDataAtLast(MyList* const list);

//删除在首部
void* myListRemoveDataAtFirst(MyList * const list);

//删除
void* myListRemoveDataAt(MyList* const list, int index);

//删除对象,返回是否删除成功
int myListRemoveDataObject(MyList* const list, void * data);

//长度
int myListGetSize(const MyList * const list);

//打印
void myListOutput(const MyList * const list, void(*pt)(const void * const));

//取得数据
void* myListGetDataAt(const MyList * const list, int index);

//取得第一个数据
void* myListGetDataAtFirst(const MyList * const list);

//取得最后一个数据
void* myListGetDataAtLast(const MyList * const list);

//查找某个数据的位置,如果equal方法为空，比较地址，否则调用equal方法
//如果不存在返回-1，如果存在，返回出现的第一个位置
int myListFindDataIndex(const MyList * const list, void * data);

//创建遍历器
MyListIterator* createMyListIterator(const MyList * const list);

//释放遍历器
void freeMyListIterator(MyListIterator* iterator);

//遍历器是否有下一个元素
int myListIteratorHasNext(const MyListIterator* const iterator);

//返回遍历器的下一个元素
void * myListIteratorNext(MyListIterator* const iterator);

#endif // LIST_H_INCLUDED
