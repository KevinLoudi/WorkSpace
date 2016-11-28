#include <iostream>
#include <cctype>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define DEBUG

using namespace std;

int func(int *p);
int m_max(int *a, int *b);
/*replace sub2 with sub3 in str*/
char* m_replace(const char* str, const char* sub1, const char* sub2, char* out );
/*strcat two string*/
char* m_strcat(char *dest, const char* src);
/*delete sub string in str*/
char* m_delet(char* str, char sub);
/*delete part of the str*/
char* m_delet_block(char* str, int pos, int len);
/*loop move the string by n*/
char* m_loopmove(char* str, int n);
/*add number*/
char* m_addBigInt(char* num1, char* num2);
/*reverse the string*/
char* m_strev1(const char* str);
//will occur runtime error
char* m_strev2(char* str);
/*String Manipulation*/
ostream & m_usestring(ostream & ros);


int main()
{
    /*int a=10;
    int *pa=&a;
    int c=(*func)(pa);
    std::cout<<c<<std::endl; */
    /*int a=32;
    int b=45;
    int* pa=&a; int* pb=&b;
    std::cout<<(*m_max)(pa,pb)<<std::endl;

    const char str1[]="abc";
    const char str2[]="abc";
    char* str3="abc";
    char* str4="abc";
    char** pstr3=&str3;
    char** pstr4=&str4;
    std::cout<<(&str3)<<std::endl;
    std::cout<<(&str4)<<std::endl;
    std::cout<<(strcmp(str3,str4))<<std::endl;*/

    /*char str[10] = "abcdef";
    char sub1[] ="cd";
    char sub2[] = "45";
    char out[100] = "";
    cout<<m_replace(str,sub1,sub2,out)<<endl;

    char* str2=new char[strlen((str)+strlen(sub1)+1)];
    str2[0] = '\0'; //you need to add an end mark in the heap-allocated string, otherwise it will be random string
    cout<<str2<<endl;
    cout<<(str2=m_strcat(str,sub1))<<endl;

    cout<<m_delet(str,'c')<<endl;

    char sstr[]="abcdefg";
    char* sstr1=sstr;
    cout<<m_delet_block(sstr,1,2)<<endl;
    char* sstr2=sstr;
    cout<<m_loopmove(sstr2,2)<<endl;*/

    /*char* num1="123456";
    char* num2="482983";
    //cout<<m_addBigInt(num1,num2)<<endl;
    //cout<<m_strev1(num1)<<endl;
    cout<<m_strev2(num1)<<endl;*/

    cout<<m_usestring(cout);
    return 0;
}

ostream & m_usestring(ostream & ros)
{
    //using c++ 11
    using std::string;
    string name;
    cout << "Enter your name: " << flush;
    //cin >> name;
    //getline(cin,name); //read a whole line
    name="";
    name+=" Gengyu";
    //convert all characters to upper case
    for(string::size_type i=0; i<name.length();i++)
    {
        name[i]=toupper(name[i]);
    }
    //search facilities
    string sub="U";
    string::size_type  pos=name.find(sub);
    if(pos!=string::npos)
    {
        ros<<name<<" have found "<<sub<<" at "<<pos<<endl;
    }
    sub="G";
    //find_first_not_of works in a similar way
    if((pos=name.find_first_of(sub))!=string::npos)
    {
        ros<<"have found "<<sub<<" at "<<pos<<endl;
        ros<<name.substr(2,6)<<endl;
        ros<<name.replace(0,3,"Kevin");
    }
    //parse string



    return ros;
}

char* m_strev2(char* str)
{
    char* head=str;
    char* tail=new char[strlen(str)+1];   //str+strlen(str)-1;
    strcpy(tail,str);
    char* ret=tail;

    #ifdef DEBUG
    cout<<"Debug messages...."<<endl;
    cout<<*head<<" "<<*tail<<endl;
    cout<<head<<endl; //p and head have identical address
    cout<<"End of Debug messages...."<<endl;
    #endif // DEBUG

    while(tail>head)
    {
        *tail=*tail+*head;
        *head=*tail-*head;
        *tail=*tail-*head;

        --tail;
        ++head;
    }

    #ifdef DEBUG
    cout<<"Debug messages...."<<endl;
    cout<<*head<<" "<<*tail<<endl;
    cout<<head<<endl; //p and head have identical address
    cout<<"End of Debug messages...."<<endl;
    #endif // DEBUG
    return ret;
}

char* m_strev1(const char* str)
{
    char* tmp=new char[strlen(str)+1];
    strcpy(tmp,str);
    char* ret=tmp;
    char* p=tmp+strlen(str)-1; //initial a pointer to the tail

    #ifdef DEBUG
    cout<<"Debug messages...."<<endl;
    cout<<&ret<<" "<<&tmp<<endl;
    cout<<p<<endl; //p and head have identical address
    cout<<"End of Debug messages...."<<endl;
    #endif // DEBUG

    while(p>tmp)
    {
        char t= *tmp;
        *tmp=*p;
        *p=t;

        --p;
        ++tmp; //reverse the head and tail
    }

    return ret;
}

char* m_addBigInt(char* num1, char* num2)
{
    int dec=0;
    int cur1=strlen(num1)-1; //move to the current calculate position
    int cur2=strlen(num2)-1;
    int maxlen=strlen(num1)>=strlen(num2)?strlen(num1)+1:strlen(num2)+1;

    char* rst=(char*)malloc(maxlen+1); //allocate memory for result
    if(rst=NULL)
    {
        printf("malloc error!\n");
        exit(1);
    }
    rst[maxlen]='\0';

    int curr=strlen(rst)-1;  //move to the current result-hold position
    while((cur1>=0)&&(cur2>=0))
    {
        rst[curr]=((num1[cur1]-'0')+(num2[cur2]-'0')+dec)%10+'0'; //calculate one bit 本位计算
        dec=((num1[cur1]-'0')+(num2[cur2]-'0')+dec)/10; //update decade 进位计算
        --cur1;
        --cur2;
        --curr;
    }

    //if one of  num1, num2 have finished, while the other remained,
    //add with 进位 dec
    while(cur1>=0)
    {
        rst[curr]=((num1[cur1]-'0')+dec)%10+'0';
        dec=((num1[cur1]-'0')+dec)/10;
        --cur1;
        --curr;
    }
    while(cur2>=0)
    {
        rst[curr]=((num2[cur2]-'0')+dec)%10+'0';
        dec=((num2[cur2]-'0')+dec)/10;
        --cur2;
        --curr;
    }
    rst[0]=dec+'0';

    //judge if the highest bit is not 0
    if(rst[0]!='0')
    {
        return rst;
    }
    else
    {
        return rst+1;
    }
}

char* m_loopmove(char* str, int n)
{
    char* temp=(char*)malloc(n); //allocate heap memory
    temp[0]='\0';
    char* head=str;

    while(*str++);
    int len=str-head-1; //obtain the length of the string through     tail-head+1

    n=n%len; //if n is greater than len, deduct it
    int i=0;
    for(; i<n ;i++)
    {
        temp[i]=head[len-n+i]; //move the tail part of the string to the temp memory
    }
    for(i=len-1;i>=n;i--)
    {
        head[i]=head[i-n]; //move the origin head to tail
    }
    for(i=0;i<n;i++)
    {
        head[i]=temp[i]; //initial new head by temp memory
    }

    free(temp);
    #ifdef DEBUG
    cout<<"Debug messages...."<<endl;
    cout<<head<<endl;
    cout<<str<<endl; //p and head have identical address
    cout<<"End of Debug messages...."<<endl;
    #endif // DEBUG
    return head;
}

char* m_delet_block(char* str, int pos, int len)
{
    if(str==NULL||(pos+len)>strlen(str)||pos<1)
    {
        return NULL;
    }
    char* p=str+pos-1; //point to the being deleted part

    while(*p && *(p+len)) //break until reach the end
    {
        //cover the part from p to p+len by move the back elements forward
        *p=*(p+len);
        p++;
    }

    *p='\0';

    return str;
}

char* m_delet(char* str,  char sub)
{
    if(str==NULL)
    {
        return NULL;
    }

    char* p = str;
    char* head=p;
    #ifdef DEBUG
    cout<<"Debug messages...."<<endl;
    //cout<<&p<<endl;
    //cout<<&head<<endl; //p and head have identical address
    cout<<"End of Debug messages...."<<endl;
    #endif // DEBUG

    if (*p) //discuss for first char
    {
        *str++ = *p;
    }
    
    while(*p++)
    {
        //every char not equal sub is part of the new str
        if(*p!=sub)
        {
            *str++=*p;
        }
    }
    *str ='\0';

    return head;
}

char* m_strcat(char *dest, const char* src)
{
    char* ret=dest;

    while(*dest++); //reach the end of dest string
    dest--; //one-step backward

    while(*dest++=*src++); //continuing copy src to dest untill src reach the end

    return ret;
}

char* m_replace(const char* str, const char* sub1, const char* sub2, char* out )
{
    char* pout=NULL; pout=out;
    const char* pstr=NULL; pstr=str; //tmp string to find sub-string
    int lensub1=strlen(sub1);
    int lensub2=strlen(sub2);

    while(*pstr!=0)
    {
        pstr=strstr(pstr,sub1);
        if(pstr!=NULL)
        {
            memcpy(pout,str,pstr-str); //copy the part before the sub1
            pout+=pstr-str;

            memcpy(pout,sub2,lensub2); //replace sub1 part with sub2
            pout+=lensub2;

            pstr+=lensub1; //prepare for the next movement, move pointer to the original string pass over sub1
            str=pstr;
        }
       else
       {
           //cannot find the sub string
           break;
       }
    }
    *pout='\0';
    if(*str!='\0')
    {
        strcpy(pout,str);
    }
  return out; //out;
}


int m_max(int *a, int *b)
{
    return *a>*b? *a: *b;
}
