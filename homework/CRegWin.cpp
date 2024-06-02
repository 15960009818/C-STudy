#include"CRegWin.h"
#include"CStaff.h"
#include"CWindow.h"


CRegWin::CRegWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	this->id=CStaff::count+1000;
	this->Label=new CLabel(40,7,0,0,"OrderDishע��ϵͳ");
	this->idLabel=new CLabel(30,10,0,0,"id      :");
	this->userLabel=new CLabel(30,13,0,0,"�� �� ����");
	this->pwdLabel=new CLabel(30,16,0,0,"��    �룺");
	this->confirmLabel=new CLabel(30,19,0,0,"ȷ�����룺");
	this->chooseLabel=new CLabel(30,21,0,0,"1.����Ա 2.���� 3.����Ա��");
	this->roleLabel=new CLabel(30,23,0,0,"��ɫ������");
	this->userEdit=new CEdit(40,13,25,3,"",3,1,8);
	this->pwdEdit=new CEdit(40,16,25,3,"",1,0,8);
	this->confirmEdit=new CEdit(40,19,25,3,"",1,0,8);
	this->roleEdit=new CEdit(40,23,25,3,"",1,1,1);
	this->regBtn=new CButton(30,26,7,3,"ȷ��");
	this->escBtn=new CButton(60,26,7,3,"�˳�");
	this->addCtrl(this->Label);//0
	this->addCtrl(this->idLabel);//1
	this->addCtrl(this->userLabel);//2
	this->addCtrl(this->pwdLabel);//3
	this->addCtrl(this->confirmLabel);//4
	this->addCtrl(this->chooseLabel);//5
	this->addCtrl(this->roleLabel);//6
	this->addCtrl(this->userEdit);//7
	this->addCtrl(this->pwdEdit);//8
	this->addCtrl(this->confirmEdit);//9
	this->addCtrl(this->roleEdit);//10
	this->addCtrl(this->regBtn);//11
	this->addCtrl(this->escBtn);//12
}

CRegWin::~CRegWin()
{
}
void CRegWin::showWin()
{
	CWindow::showWin();
	CTools::gotoxy(40,10);
	cout<<this->id;
}
int CRegWin::doAction()
{
	switch(this->ctrl_index)
	{
	case 11:
		CStaff::arr[CStaff::count++]=new CStaff(
			this->userEdit->getContent(),
			this->pwdEdit->getContent(),
			atoi(this->roleEdit->getContent())
			);
		printf("ע��ɹ�");
		return LOGINWIN;
	case 12:
		return LOGINWIN;
	default:
		break;
	}
	return REGWIN;
}
