#include"CWindow.h"
#include"CTools.h"
#include"CLoginWin.h"
#include"CStaff.h"
CLoginWin::CLoginWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{

	this->title=new CLabel(40,7,0,0,"OrderDish点菜系统");
	this->userLabel=new CLabel(30,11,0,0,"用 户 名：");
	this->pwdLabel=new CLabel(30,14,0,0,"密    码：");
	this->userEdit=new CEdit(40,11,25,3,"",4,1,8);
	this->pwdEdit=new CEdit(40,14,25,3,"",1,0,8);
	this->loginBtn=new CButton(30,21,7,3,"登录");
	this->regBtn=new CButton(45,21,7,3,"注册");
	this->escBtn=new CButton(60,21,7,3,"退出");
	this->addCtrl(this->title);//0
	this->addCtrl(this->userLabel);//1
	this->addCtrl(this->pwdLabel);//2
	this->addCtrl(this->userEdit);//3
	this->addCtrl(this->pwdEdit);//4
	this->addCtrl(this->loginBtn);//5
	this->addCtrl(this->regBtn);//6
	this->addCtrl(this->escBtn);//7
}

CLoginWin::~CLoginWin()
{

}

int CLoginWin::doAction()
{
	switch(this->ctrl_index)
	{
	case 5:
		CStaff::index=staffJudge(this->ctrlArr[3]->getContent(), CStaff::arr, CStaff::count);
		return CLoginWin::doLogin(CStaff::index,this->ctrlArr[4]->getContent(),CStaff::arr);
	case 6:
		return REGWIN;
	case 7:
		return ESC;
	default:
		return LOGINWIN;
	}
	return LOGINWIN;
}
int CLoginWin::doLogin(int index,char *pwd,CStaff *staffArr[])
{
	if(index==-1)
	{
		printf("\n用户名不存在\n");
		system("pause");
		return 0;
	}

	if(strcmp(pwd,staffArr[index]->getPwd())==0)
	{
			printf("\n登陆成功\n");
			switch(staffArr[index]->getRole()){
			case ADMIN:return 1;
			case MANAGER:return 2;
			case WAITER:return 3;
		}
	}
	else 
	{
		printf("\n密码错误\n");
		system("pause");
		return 0;
	}

	return 0;
}