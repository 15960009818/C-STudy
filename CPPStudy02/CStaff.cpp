//
// Created by 1 on 2024/5/18.
//

#include "CStaff.h"
#include <string.h>
#include "iostream"

char * CStaff::getPwd() {
    return this->pwd;
}
//��C++�У��ַ�����������"123456"����const char*����
// ����strcpy�ȴ�ͳ��C�ַ�������Ҫ��Ŀ����һ����const char*���͡�����ܵ��¾�������
// �ر������Ŀ��������char*�������ͼ���ַ�������ֱ�Ӹ�ֵ��char*
void CStaff::setPwd(char const* newpwd) {
    //ͨ��copyʵ����ֵ����
//    strcpy(this->pwd,newpwd);
    strncpy(this->pwd, pwd, sizeof(this->pwd) - 1);
    this->pwd[sizeof(this->pwd) - 1] = '\0';
}
//�ͷ�ָ���Ա
CStaff::~CStaff() {
    std::cout<<"��ӡ��������"<<std::endl;
}
//���캯������
CStaff::CStaff(int id, char *name, char *pwd, int role) {
    this->id = id;
    memset(this->name, 0, sizeof(this->name));
    strncpy(this->name, name, sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0'; // ȷ���ַ����� null ��β
    memset(this->pwd, 0, sizeof(this->pwd));
    strncpy(this->pwd, pwd, sizeof(this->pwd) - 1);
    this->pwd[sizeof(this->pwd) - 1] = '\0'; // ȷ���ַ����� null ��β
    this->role = role;
}

void CStaff::printf() {
    std::cout<<"id"<< this->id<<"name"<<this->name<<"pwd"<<this->getPwd()<<std::endl;

}
