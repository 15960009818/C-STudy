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
	CMenu::head->append(new CMenu("ţ����","�ó�",18));
	CMenu::head->append(new CMenu("����","�ܺó�",20));
	CMenu::head->append(new CMenu("����","�ܺó�",12));
	CMenu::head->append(new CMenu("���","�ܺó�",14));
	int i=0;
	//waiterWin();

	//������Ҫ���麯�� �����������ʵ�ֺ���
	CWindow *winArr[10]={
		new CLoginWin(10,5,90,25),		//��½���� -0
		new CAdminWin(10,5,90,25),		//����Ա������ -1
		new CManagerWin(10,5,90,25),		//����������   -2
		new CWaiterWin(10,5,90,25),		//����Ա������  -3
		new CRegWin(10,5,90,25),  //ע�����  -4
		new COpenTableWin(10,5,90,25), //����Ա���� -5
		new COrderDishWin(10,5,90,25), //����Ա��� -6
		new CCancelDishWin(10,5,90,25), //����Ա�˲� -7
		new CCloseBillWin(10,5,90,25), //����Ա���� -8
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