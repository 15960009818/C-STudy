//
// Created by 1 on 2024/5/15.
//

#include "main.h"
#include <iostream>
using namespace std;//ʹ�ñ�׼�����ռ䣬����C
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
int main(){
    int i = 30;
    s1::myprint();//�������
    s2::myprint();
    //���Ի�ȡ��ȫ�ֺ;ֲ�������ֵ��::Ϊȫ�ֱ�����
    cout<<"ȫ�ֱ���"<<::i<<endl;
    demo_bool();
    return 0;
}
void demo_bool(){
    int num = 0;
    bool flag = (bool)-2;
    std::cout<<"bool flag ="<<flag<<",size = "<<sizeof (bool )<<endl;
}
