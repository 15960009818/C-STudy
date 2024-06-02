#ifndef _CMENU_H_
#define _CMENU_H_ //∑¿÷π÷ÿ∏¥±‡“Î
#include"CList.h"
#include"CData.h"
class CMenu
{
public:
	CMenu(char *name,char *info,int price);
	~CMenu();
	static int count;
	static CList *head;
	static CMenu* menuJugde(int id);
	int getId();
	char* getName();
	char* getInfo();
	int getPrice();
	void setId(int id);
	void setName(char* name);
	void setInfo(char* info);
	void setPrice(int price);
private:
	int id;
	char name[30];
	char info[30];
	int price;

};


#endif