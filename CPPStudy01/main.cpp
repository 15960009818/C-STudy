//
// Created by 1 on 2024/5/15.
//

#include "main.h"
#include <iostream>
using namespace std;//使用标准命名空间，区分C
struct Date{
    //c++定义结构体中可以为其成员自定义所占位数
//    支持c特性，内存对齐
    int year: 20;
    int month:6;
    int day:6;
};
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
void demo_new();
int main(){
    int i = 30;
    s1::myprint();//域运算符
    s2::myprint();
    //可以获取到全局和局部变量的值，::为全局变量名
    cout<<"全局变量"<<::i<<endl;
    demo_bool();
    demo_new();
    return 0;
}
void demo_bool(){
    int num = 0;
    bool flag = (bool)-2;
    std::cout<<"bool flag ="<<flag<<",size = "<<sizeof (bool )<<endl;
}
void demo_new(){
    int *p1 = NULL;
    int *p2 = NULL;
    p2 = new int ;//自动结算开辟空间，不用强转
    //c手动开辟
    p1 = (int *) malloc(sizeof (int ));
    *p1 = 10;
    *p2 = 20;
    printf("%p,%d\n",p1,*p1);
    printf("%p,%d\n",p2,*p2);
}