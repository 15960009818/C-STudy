//
// Created by 1 on 2024/5/15.
//

#include "main.h"
#include <iostream>
#include <string>
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
void demo_cin();
int add(int a,int b);
int add(int a ,char b);
void checkIp(int ip,int port = 8080);
int main(){
//    int i = 30;
//    s1::myprint();//域运算符
//    s2::myprint();
//    //可以获取到全局和局部变量的值，::为全局变量名
//    cout<<"全局变量"<<::i<<endl;
//    demo_bool();
//    demo_new();
//    demo_cin();
    int a = 10,b = 20;
    i = add(a,b);

    cout<<i<<endl;
    checkIp(1);
    checkIp(1,8082);
    return 0;
}
void demo_bool(){
    int num = 0;
    bool flag = (bool)-2;
    std::cout<<"bool flag ="<<flag<<",size = "<<sizeof (bool )<<endl;
}
//new和malloc的区别，new是运算符，malloc是函数，new不需要计算空间大小，释放方法不同，
//new会自动调用构造函数，delete自动调用析构函数，malloc void*使用需要强制转换，new出来就是对应类型指针
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
    free(p1);
    delete p2;
}

void demo_cin(){
    int id = 0,age = 0;
    string name;
    cin>>id>>name>>age;
    cout<<"id"<<id<<"name"<<name<<"age"<<age<<endl;
    string helloName = name+"hello";
//    cout<<"new:"<helloName;
}
//重载
//在编译时c++会将类型连同函数名一同写入
int add(int a,int b){
    return a+b;
}
int add(int a,char b){
    return a+b;
}
//赋默认值一定要从右到左，因为实参赋值都是从左到右
//默认值放在声明里就不要放在函数里
void checkIp(int ip,int port){
     cout<<"ip: "<<ip<<"port:  "<<port<<endl;
}