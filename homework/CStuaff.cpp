//
// Created by 1 on 2024/5/18.
//

#include "CStuaff.h"
#include <iostream>
#include <vector>

using namespace std;

// ���캯������
CStaff::CStaff(int id, const std::string& name, const std::string& pwd, int role) {
    this->id = id;
    this->name = name;
    this->pwd = pwd;
    this->role = role;
}
// ���Ա��
void CStaff::addStaff(std::vector<CStaff>& staffArr, const CStaff& newStaff) {
    staffArr.push_back(newStaff);
}
void printfStaffInfo(CStaff *staffArr[],int staffCount)
{
    int i=0;
    printf("\nid\tname\tpwd\trole\n");
    for(i=0;i<staffCount;i++)
    {
        printf("%d\t%s\t%s\t",staffArr[i]->id,staffArr[i]->name.c_str(),staffArr[i]->pwd.c_str());
        switch(staffArr[i]->role)
        {
            case ADMIN:printf("����Ա\n");break;
            case MANAGER:printf("����\n");break;
            case WAITER:printf("����Ա\n");break;
        }

    }
}
void addStaff(CStaff *staffArr,int *staffCount ,CStaff newStaff)
{
    staffArr[(*staffCount)++]=newStaff;
}