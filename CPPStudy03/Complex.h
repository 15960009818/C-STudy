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
    //�ӷ����������
    CComplex operator+(CComplex &num);
    //һԪ�����ǰ��++���أ�������thisָ��
    CComplex &operator++();
    //++��Ա
    CComplex operator++(int );
    friend CComplex operator*(CComplex &a, CComplex &b);
protected:

private:
    int real;  // ʵ��
    int imag;  // �鲿
};
#endif //C_STUDY_COMPLEX_H
