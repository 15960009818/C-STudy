#ifndef _CSTAFF_H_
#define _CSTAFF_H_

#define ADMIN 1 //����Ա
#define MANAGER 2 //����
#define WAITER 3  //����Ա

#include"CTools.h"




class Staff //��ʾ�Զ�����������--�ṹ��
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
    //�������� ������
    int id;
    char name[10];
    char pwd[10];
    int role;
};


void printfStaffInfo(Staff *staffArr,int staffCount);
void addStaff(Staff *staffArr,int *staffCount ,Staff newStaff);
int staffJudge(char *name,Staff *staffArr[],int staffCount);
#endif