//
// Created by 1 on 2024/5/25.
//

#include "Complex.h"
#include <iostream>
using namespace std;
CComplex::CComplex(int real,int imag){
    this->real=real;
    this->imag=imag;
}
int CComplex::getreal(){
    return this->real;
}
int CComplex::getimag(){
    return this->imag;

}
CComplex CComplex::operator+(CComplex &num){
    CComplex tmp;
    tmp.real = this->real+num.real;
    tmp.imag = this->imag+num.imag;
    return tmp;
}
CComplex &CComplex:: operator++(){
    this->real++;
    this->imag++;
    return *this;
}
CComplex CComplex::operator++(int){

    CComplex tmp;
    tmp.real = this->real;
    tmp.imag = this->imag;
    cout<<"ºóÖÃ++"<<endl;
    this->real++;
    this->imag++;
    return tmp;
}