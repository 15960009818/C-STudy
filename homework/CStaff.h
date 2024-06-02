#ifndef _CSTAFF_H_
#define _CSTAFF_H_

#define ADMIN 1 //����Ա
#define MANAGER 2 //����
#define WAITER 3  //����Ա

#include"CTools.h"



class CStaff//��ʾ�Զ�����������--�ṹ��
{
public:
	static int count;
	static int index;
	static CStaff *arr[10];
	CStaff();
	CStaff(int id,char*name,char *pwd,int role);
	~CStaff();
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


void printfStaffInfo(CStaff staffArr,int staffCount);
void addStaff(CStaff *staffArr[],int *staffCount ,CStaff *newStaff);
int staffJudge(char *name,CStaff *staffArr[],int staffCount);
#endif