//
// Created by 1 on 2024/5/18.
//
#include <iostream>
using namespace std;
#include "CStaff.h"
#include <cstring>

int main(){
    //第一种创建对象方法
    CStaff cStaff;
//    cStaff.id = 1001;
//    strcpy(cStaff.name,"admins");
    cout<<"id"<<cStaff.id<<"name"<<cStaff.name<<"pwd"<<cStaff.getPwd()<<endl;
    CStaff *pstaff1 = new CStaff(1002,"abc","45645",MANAGER);
    cout<<"id"<<pstaff1->id<<"name"<<pstaff1->name<<"pwd"<<pstaff1->getPwd()<<endl;
//    cStaff.setPwd("123456");
//    cout << "pwd: " << cStaff.getPwd() << endl;
//    //类指针 4字节，第二种创建对象方法
//    CStaff *pstaff = &cStaff;
//    //第三种创建对象方法
//    CStaff *pStaff1 = new CStaff;
//    pStaff1->id = 1002;
    return 0;
}