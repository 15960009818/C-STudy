#include<iostream>
#include"CTools.h"
#include"CWindow.h"
#include"CMenu.h"
#include"CManagerWin.h"
#include"CWaiterWin.h"
#include"CLoginWin.h"
#include"CAdminWin.h"
#include"CRegWin.h"
#include"COpenTableWin.h"
#include"COrderDishWin.h"
#include"CCancelDish.h"
#include"CCloseBillWin.h"
using namespace std;
int main()
{
	CMenu::head->append(new CMenu("牛肉面","好吃",18));
	CMenu::head->append(new CMenu("拌面","很好吃",20));
	CMenu::head->append(new CMenu("扁肉","很好吃",12));
	CMenu::head->append(new CMenu("香锅","很好吃",14));
	int i=0;
	//waiterWin();

	//基类中要纯虚函数 ，派生类必须实现函数
	CWindow *winArr[10]={
		new CLoginWin(10,5,90,25),		//登陆界面 -0
		new CAdminWin(10,5,90,25),		//管理员主界面 -1
		new CManagerWin(10,5,90,25),		//经理主界面   -2
		new CWaiterWin(10,5,90,25),		//服务员主界面  -3
		new CRegWin(10,5,90,25),  //注册界面  -4
		new COpenTableWin(10,5,90,25), //服务员开桌 -5
		new COrderDishWin(10,5,90,25), //服务员点菜 -6
		new CCancelDishWin(10,5,90,25), //服务员退菜 -7
		new CCloseBillWin(10,5,90,25), //服务员结账 -8
	};

	while(1)
	{
		winArr[i]->showWin();
		winArr[i]->winRun();
		i=winArr[i]->doAction();
		CTools::gotoxy(20,26);
		system("pause");
		system("cls");
	}

}