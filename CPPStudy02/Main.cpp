//
// Created by 1 on 2024/5/18.
//
#include <iostream>
using namespace std;
#include "CStaff.h"
#include <cstring>

int main(){
    CStaff cStaff;
    cStaff.id = 1001;
    strcpy(cStaff.name,"admins");
    cout<<"id"<<cStaff.id<<"name"<<cStaff.name<<endl;

    cStaff.setPwd("123456");
    cout << "pwd: " << cStaff.getPwd() << endl;

    return 0;
}