#include "myString.h"
#include<iostream>
using namespace __myString;
int main(){
    char* s;
    while(std::cin>>s){
    std::cout<<strlen(s)<<std::endl;
    myString* temp = new myString(s);
    myString temp2 = myString("sffdsfa");
    myString temp3=*temp;//调用拷贝构造函数
    // myString temp3; 
    // temp3 = *temp;
    *temp=temp2;
    std::cout<<"t2c:"<<*temp->ptr->cnt<<std::endl;
    temp3=myString("temp3");
    std::cout<<"temp:"<<*temp<<std::endl;
    std::cout<<"temp2:"<<temp2<<" "<<mystrlen(temp2)<<std::endl;
    std::cout<<"temp3"<<temp3<<" "<<mystrlen(temp3)<<std::endl;
    delete(temp);
    }
    return 0;
}


