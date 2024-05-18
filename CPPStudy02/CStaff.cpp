//
// Created by 1 on 2024/5/18.
//

#include "CStaff.h"
#include <string.h>
char * CStaff::getPwd() {
    return this->pwd;
}
//在C++中，字符串常量（如"123456"）是const char*类型
// ，而strcpy等传统的C字符串函数要求目标是一个非const char*类型。这可能导致警告或错误，
// 特别是如果目标类型是char*或如果试图将字符串常量直接赋值给char*
void CStaff::setPwd(char const* newpwd) {
    //通过copy实现数值放入
//    strcpy(this->pwd,newpwd);
    strncpy(this->pwd, pwd, sizeof(this->pwd) - 1);
    this->pwd[sizeof(this->pwd) - 1] = '\0';
}
