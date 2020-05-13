#ifndef __myString___
#define __myString___
#include "referenceCounter.h"
#include <iostream>
#include <cstring>

namespace __myString
{
class myString
{
public:
    /* data */
    // char *mystr = nullptr;
    referenceCounter *ptr=nullptr;

public:
    inline myString(const char *chr = 0);
    inline ~myString();
    inline myString(const myString &temp);
    inline myString &operator=(const myString &s2);
    inline void* mystrcpy(char *s1, const char *s2, size_t count = 0);
    inline void swap(myString &str);
    friend inline std::ostream &operator<<(std::ostream &os, const myString &chr);
    friend inline size_t mystrlen(const myString &chr);
};

inline size_t mystrlen(const myString &chr)
{
    return strlen(chr.ptr->s);
}

// inline void myString:: swap(myString& str){
//     std::swap(*this,*str.mystr);
// }

inline void* myString::mystrcpy(char *s1, const char *s2, size_t count)
{
    std::cout<<"s2:"<<s2<<std::endl;
    count = strlen(s2);
    std::cout<<"count:"<<count<<std::endl;
    if (s1 < s2 + count && s1 > s2)
    {
        for (int i = count - 1; i >= 0; i--)
            s1[i] = s2[i];
    }
    else
    {
        for (int i = 0; i < count; i++)
            std::cout<<"s1:"<<s1[i]<<std::endl,s1[i] = s2[i];
    }
    s1[count] = '\0';
    return s1;
}

inline myString::myString(const char *chr):ptr(new referenceCounter())
{
    if (chr)
    {
        ptr->s = new char[strlen(chr) + 1];
        mystrcpy(ptr->s,chr);
    }
    else
    {
        ptr->s = new char[1];
        * ptr->s = '\0';
    }
}       

inline myString::~myString()
{
    // std::cout<<*ptr->cnt<<std::endl;
    if (!(--*ptr->cnt)){
        delete[] ptr->s;
        delete ptr;
    }
}

inline myString::myString(const myString &temp){
    if(ptr==nullptr){ 
        ptr=new referenceCounter();
        strcpy(ptr->s,temp.ptr->s);
    }else{
    ptr=temp.ptr;
    ++*ptr->cnt;
    }

    // 未用copy on write前的写法
    // if (this == &temp)
    // {
    //     // return *this;
    // }
    // else
    // {
    //     delete[] ptr->s;
    //     mystr = new char[strlen(temp.mystr) + 1];
    //     mystrcpy(mystr, temp.mystr);
    //     // return *mystr;
    // }
}

// 未用copy on write前的写法和拷贝构造一样
inline myString &myString::operator=(const myString &s2)    
{
    // --的原因是字符串原本指向的地址的引用-1
    std::cout<<"cnt:"<<*ptr->cnt<<"s:"<<ptr->s<<"s2:"<<*s2.ptr->cnt<<std::endl;
    ptr->s=s2.ptr->s;
    if(!(--*ptr->cnt)&&this!=&s2){
        delete ptr;
        ptr=new referenceCounter(); 
        ptr->s = new char[strlen(s2.ptr->s) + 1];
        std::cout<<"new:"<<*ptr->cnt<<std::endl;
        mystrcpy(ptr->s, s2.ptr->s);
    }
    std::cout<<"this:"<<(this->ptr==ptr)<<std::endl;
    return *this;
}



inline std::ostream &operator<<(std::ostream &os, const myString &chr)
{
    os << chr.ptr->s << std::endl;
}
} // namespace __myString
#endif