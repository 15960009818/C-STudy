#include"CStuaff.h"


Staff::Staff(int id,char*name,char *pwd,int role)
{
    this->id=id;
    strcpy(this->name,name);
    strcpy(this->pwd,pwd);
    this->role=role;
}
Staff::~Staff()
{

}
int Staff::getId()
{
    return this->id;
}
void Staff::setId(int id)
{
    this->id=id;
}
char *Staff::getName()
{
    return this->name;
}
void Staff::setName(char *name)
{
    strcpy(this->name,name);
}
char *Staff::getPwd()
{
    return this->pwd;
}
void Staff::setPwd(char *pwd)
{
    strcpy(this->pwd,pwd);
}
int Staff::getRole()
{
    return this->role;
}
void Staff::setRole(int role)
{
    this->role=role;
}
void printfStaffInfo(Staff *staffArr[],int staffCount)
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
void addStaff(Staff *staffArr,int *staffCount ,Staff newStaff)
{
    staffArr[(*staffCount)++]=newStaff;
}