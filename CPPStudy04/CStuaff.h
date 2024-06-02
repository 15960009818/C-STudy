#ifndef _CSTAFF_H_
#define _CSTAFF_H_

#define ADMIN 1 //管理员
#define MANAGER 2 //经理
#define WAITER 3  //服务员

#include"CTools.h"




class Staff //表示自定义数据类型--结构体
{
public:

    Staff(int id,char*name,char *pwd,int role);
    ~Staff();

    int getId();
    void setId(int id);

    char *getName();
    void setName(char *name);

    char *getPwd();
    void setPwd(char *name);

    int getRole();
    void setRole(int id);

private:
    //数据类型 属性名
    int id;
    char name[10];
    char pwd[10];
    int role;
};


void printfStaffInfo(Staff *staffArr,int staffCount);
void addStaff(Staff *staffArr,int *staffCount ,Staff newStaff);
int staffJudge(char *name,Staff *staffArr[],int staffCount);
#endif