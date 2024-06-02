//
// Created by 1 on 2024/5/25.
//

#include "main.h"
#include <iostream>
#include "CStuaff.h"
#include "Complex.h"
using namespace std;
void printStaffinfo(Staff &a){
    cout<<"id"<<a.getId()<<"name"<<a.getName()<<endl;
    //就像成员函数一样可以访问所有成员
}
CComplex operator*(CComplex &a, CComplex &b)
{
    CComplex res;
    res.real = a.real * b.real;
    res.imag = a.imag * b.imag;
    return res;
}
int main()
{
    int num = 10;
    int res = num++;
    cout << "res=" << res;
    cout << "num=" << num << endl;

    CComplex a;
    CComplex b(2, 3);
    CComplex c;

    // 1. 类成员函数运算符重载
    c = a + b;               // 隐式调用
    c = a.operator+(b);      // 显式调用

    // 2. 普通成员函数运算符重载
    c = a * b;               // 隐式调用
    c = operator*(a, b);     // 显示调用

    // 3. 自增
    // ++num    先自增，再参与运算
    // num++    先参与运算，再自增    tmp = num + 1; num = tmp; 释放 tmp
    ++a;
    b.operator++();          // 隐式调用
    a.operator++(0);         // 显式调用  后置++    c = a 自增

    c = a + b;
    cout << "real:" << a.getreal() << "; imag:" << a.getimag() << endl;
    cout << "real:" << b.getreal() << "; imag:" << b.getimag() << endl;
    cout << "real:" << c.getreal() << "; imag:" << c.getimag() << endl;

    return 0;
}