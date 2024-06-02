//
// Created by 1 on 2024/5/25.
//

#ifndef C_STUDY_COMPLEX_H
#define C_STUDY_COMPLEX_H
class CComplex
{
public:
    CComplex(int real=1,int imag=1);
    int getreal();
    int getimag();
    //加法运算符重载
    CComplex operator+(CComplex &num);
    //一元运算符前置++重载，隐藏了this指针
    CComplex &operator++();
    //++成员
    CComplex operator++(int );
    friend CComplex operator*(CComplex &a, CComplex &b);
protected:

private:
    int real;  // 实部
    int imag;  // 虚部
};
#endif //C_STUDY_COMPLEX_H
