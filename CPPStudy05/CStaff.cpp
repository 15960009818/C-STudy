#include"CStaff.h"
int CStaff::count=0;
int CStaff::index=-1;
CStaff* CStaff::arr[10]={
				new CStaff(1001,"admins","123123",ADMIN),
				new CStaff(1002,"manager","123123",MANAGER),
				new CStaff(1003,"waiter","123123",WAITER)
};

CStaff::CStaff(int id , char*name,char *pwd,int role)
{
	this->id=1001+CStaff::count;
	CStaff::count++;
	memset(this->name,0,sizeof(this->name));
	memset(this->pwd,0,sizeof(this->pwd));
	strcpy(this->name,name);
	strcpy(this->pwd,pwd);
	this->role=role;
}

CStaff::~CStaff()
{

}
int CStaff::getId()
{
	return this->id;
}
void CStaff::setId(int id)
{
	this->id=id;
}
char *CStaff::getName()
{
	return this->name;
}
void CStaff::setName(char *name)
{
	strcpy(this->name,name);
}
char *CStaff::getPwd()
{
	return this->pwd;
}
void CStaff::setPwd(char *pwd)
{
	strcpy(this->pwd,pwd);
}
int CStaff::getRole()
{
	return this->role;
}
void CStaff::setRole(int role)
{
	this->role=role;
}
void printfStaffInfo(CStaff *staffArr[],int staffCount)
{
	int i=0;
	printf("\nid\tname\tpwd\trole\n");
	for(i=0;i<staffCount;i++)
	{
		printf("%d\t%s\t%s\t",staffArr[i]->getId(),staffArr[i]->getName(),staffArr[i]->getPwd());
		switch(staffArr[i]->getRole())
		{
		case ADMIN:printf("管理员\n");break;
		case MANAGER:printf("经理\n");break;
		case WAITER:printf("服务员\n");break;
		}

	}
}
void addStaff(CStaff *staffArr[],int *staffCount ,CStaff *newStaff)
{
	staffArr[(*staffCount)++]=newStaff;
}

int staffJudge(char *name,CStaff *staffArr[],int staffCount)
{
	int i=0,flag=0;
	for(i=0;i<staffCount;i++)
	{
		if(strcmp(name,staffArr[i]->getName())==0)
		{
			return i;
		}
	}
	return -1;
}


