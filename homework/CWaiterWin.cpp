#include"CWindow.h"
#include"CTools.h"
#include"CWaiterWin.h"

CWaiterWin::CWaiterWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	this->title=new CLabel(40,6,0,0,"服务员功能界面");
	this->button1=new CButton(40,9,20,3,"开          桌");
	this->button2=new CButton(40,12,20,3,"点          菜");
	this->button3=new CButton(40,15,20,3,"退          菜");
	this->button4=new CButton(40,18,20,3,"结          账");
	this->button5=new CButton(40,21,20,3,"修  改  密  码");
	this->button6=new CButton(40,24,20,3,"注          销");
	this->button7=new CButton(40,27,20,3,"退          出");

	this->addCtrl(this->title);//0
	this->addCtrl(this->button1);//1
	this->addCtrl(this->button2);//2
	this->addCtrl(this->button3);//3
	this->addCtrl(this->button4);//4
	this->addCtrl(this->button5);//5
	this->addCtrl(this->button6);//5
	this->addCtrl(this->button7);//5
}

CWaiterWin::~CWaiterWin()
{

}

int CWaiterWin::doAction()
{
	switch(this->ctrl_index)
	{
	case 1:
		return OPENTABLEWIN;
	case 2:
		return ORDERDISHWIN;
	case 3:
		return CANCELDISHWIN;
	case 4:
		return CLOSEBILLWIN;
	case 5:
//		return WAITERPWDMODIFYWIN;
	case 7:
		return LOGINWIN;
	}

	return WAITERWIN;
}