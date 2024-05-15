//
// Created by 1 on 2024/5/15.
//

#include "main.h"
#include <iostream>
using namespace std;//使用标准命名空间，区分C
//命名空间相当于单独开辟了一片空间
namespace s1{
    int i=10;
    void myprint(){
        cout<<i<<endl;
    }
}

namespace s2{
    int i=20;
    void myprint(){
        cout<<i<<endl;
    }
}
int i = 100;
void demo_bool();
int main(){
    int i = 30;
    s1::myprint();//域运算符
    s2::myprint();
    //可以获取到全局和局部变量的值，::为全局变量名
    cout<<"全局变量"<<::i<<endl;
    demo_bool();
    return 0;
}
void demo_bool(){
    int num = 0;
    bool flag = (bool)-2;
    std::cout<<"bool flag ="<<flag<<",size = "<<sizeof (bool )<<endl;
}
