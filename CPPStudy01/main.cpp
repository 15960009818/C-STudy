//
// Created by 1 on 2024/5/15.
//

#include "main.h"
#include <iostream>
#include <string>
using namespace std;//ʹ�ñ�׼�����ռ䣬����C
struct Date{
    //c++����ṹ���п���Ϊ���Ա�Զ�����ռλ��
//    ֧��c���ԣ��ڴ����
    int year: 20;
    int month:6;
    int day:6;
};
//�����ռ��൱�ڵ���������һƬ�ռ�
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
//    s1::myprint();//�������
//    s2::myprint();
//    //���Ի�ȡ��ȫ�ֺ;ֲ�������ֵ��::Ϊȫ�ֱ�����
//    cout<<"ȫ�ֱ���"<<::i<<endl;
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
//new��malloc������new���������malloc�Ǻ�����new����Ҫ����ռ��С���ͷŷ�����ͬ��
//new���Զ����ù��캯����delete�Զ���������������malloc void*ʹ����Ҫǿ��ת����new�������Ƕ�Ӧ����ָ��
void demo_new(){
    int *p1 = NULL;
    int *p2 = NULL;
    p2 = new int ;//�Զ����㿪�ٿռ䣬����ǿת
    //c�ֶ�����
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
//����
//�ڱ���ʱc++�Ὣ������ͬ������һͬд��
int add(int a,int b){
    return a+b;
}
int add(int a,char b){
    return a+b;
}
//��Ĭ��ֵһ��Ҫ���ҵ�����Ϊʵ�θ�ֵ���Ǵ�����
//Ĭ��ֵ����������Ͳ�Ҫ���ں�����
void checkIp(int ip,int port){
     cout<<"ip: "<<ip<<"port:  "<<port<<endl;
}