#include"CWindow.h"
#include"CAdminWin.h"
CAdminWin::CAdminWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	this->title=new CLabel(40,8,0,0,"  管理员界面");
	this->button1=new CButton(40,11,20,3,"台桌管理");
	this->button2=new CButton(40,14,20,3,"菜谱管理");
	this->button3=new CButton(40,17,20,3,"人员管理");
	this->button4=new CButton(40,20,20,3,"注    销");
	this->button5=new CButton(40,23,20,3,"退    出");

	this->addCtrl(this->title);//0
	this->addCtrl(this->button1);//1
	this->addCtrl(this->button2);//2
	this->addCtrl(this->button3);//3
	this->addCtrl(this->button4);//4
	this->addCtrl(this->button5);//5
}

CAdminWin::~CAdminWin()
{

}

int CAdminWin::doAction()
{
	switch(this->ctrl_index)
	{
	case 1:
//		return TABLEMANAGEWIN;
	case 2:
//		return MENUMANAGEWIN;
	case 3:
//		return STAFFMANAGEWIN;
	case 4:
		return LOGINWIN;
	case 5:
		return LOGINWIN;
	}
	return LOGINWIN;
}

