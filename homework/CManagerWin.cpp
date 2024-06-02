#include"CWindow.h"
#include"CTools.h"
#include"CManagerWin.h"
CManagerWin::CManagerWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	this->title=new CLabel(40,8,0,0,"  经理功能界面");
	this->button1=new CButton(40,11,20,3,"营收汇总");
	this->button2=new CButton(40,14,20,3,"注销");
	this->button3=new CButton(40,17,20,3,"退出");

	this->addCtrl(this->title);//0
	this->addCtrl(this->button1);//1
	this->addCtrl(this->button2);//2
	this->addCtrl(this->button3);//3

}

CManagerWin::~CManagerWin()
{

}

int CManagerWin::doAction()
{
	switch(this->ctrl_index)
	{
	case 1:
	case 2:
	case 3:
		return LOGINWIN;
	}
	return MANAGERWIN;
}
