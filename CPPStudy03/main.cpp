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
    //�����Ա����һ�����Է������г�Ա
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

    // 1. ���Ա�������������
    c = a + b;               // ��ʽ����
    c = a.operator+(b);      // ��ʽ����

    // 2. ��ͨ��Ա�������������
    c = a * b;               // ��ʽ����
    c = operator*(a, b);     // ��ʾ����

    // 3. ����
    // ++num    ���������ٲ�������
    // num++    �Ȳ������㣬������    tmp = num + 1; num = tmp; �ͷ� tmp
    ++a;
    b.operator++();          // ��ʽ����
    a.operator++(0);         // ��ʽ����  ����++    c = a ����

    c = a + b;
    cout << "real:" << a.getreal() << "; imag:" << a.getimag() << endl;
    cout << "real:" << b.getreal() << "; imag:" << b.getimag() << endl;
    cout << "real:" << c.getreal() << "; imag:" << c.getimag() << endl;

    return 0;
}