#ifndef ___referenceCounter
#define ___referenceCounter
#include"myString.h"
class referenceCounter
{
    public:
        int* cnt=nullptr;
        char *s=nullptr;
        referenceCounter() : cnt(new int(1)), s(new char[1])
        {
            s[0]='\0';
        }
        friend class mySring;
};
#endif