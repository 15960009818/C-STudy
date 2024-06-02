#include"CMenu.h"
CList *CMenu::head=new CList();
int CMenu::count=0; 

#include<string.h>
CMenu::CMenu(char *name,char *info,int price)
{
	this->id=1001+CMenu::count;
	CMenu::count++;
	strcpy(this->name,name);
	strcpy(this->info,info);
	this->price=price;
	
}
CMenu::~CMenu()
{
}

int CMenu::getId()
{
	return this->id;
}
char* CMenu::getName()
{
	return this->name;
}
char* CMenu::getInfo()
{
	return this->info;
}
int CMenu::getPrice()
{
	return this->price;
}
void CMenu::setId(int id)
{
	this->id=id;
}
void CMenu::setName(char* name)
{
	strcpy(this->name,name);
}
void CMenu::setInfo(char* info)
{
	strcpy(this->info,info);
}
void CMenu::setPrice(int price)
{
	this->price=price;
}

CMenu* CMenu::menuJugde(int id)
{
	CNode *ptmp=CMenu::head->gethead();
	CMenu *pmenu=NULL;
	int count=0;
	while(ptmp->pnext!=NULL)
	{
		ptmp=ptmp->pnext;
		pmenu=static_cast<CMenu*>(ptmp->pdata);
		if(pmenu->getId()==id)
		{
			return pmenu;
		}
		count++;
	}
	return NULL;
}