//
// Created by 1 on 2024/5/18.
//

#include "CStaff.h"
#include <string.h>
// ���캯������
CStaff::CStaff(int id, const char* name, const char* pwd, int role) {
    this->id = id;
    memset(this->name, 0, sizeof(this->name));
    strncpy(this->name, name, sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0'; // ȷ���ַ����� null ��β
    memset(this->pwd, 0, sizeof(this->pwd));
    strncpy(this->pwd, pwd, sizeof(this->pwd) - 1);
    this->pwd[sizeof(this->pwd) - 1] = '\0'; // ȷ���ַ����� null ��β
    this->role = role;
}

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

