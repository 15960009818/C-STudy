
#include"CTools.h"
#include"COpenTableWin.h"
#include"CTable.h"
#include"COrder.h"
COpenTableWin::COpenTableWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	this->title=new CLabel(40,7,0,0,"开桌(从1001开始)");
	this->Label=new CLabel(30,9,0,0,"请输入桌号id：");
	this->idEdit=new CEdit(44,9,20,3,"",1,1,8);
	this->orderBtn=new CButton(65,9,7,3,"开桌");
	this->escBtn=new CButton(78,9,7,3,"返回");
	this->addCtrl(this->title);//0
	this->addCtrl(this->Label);//1
	this->addCtrl(this->idEdit);//2
	this->addCtrl(this->orderBtn);//3
	this->addCtrl(this->escBtn);//4
}

COpenTableWin::~COpenTableWin()
{

}

int COpenTableWin::doAction()
{
	switch(this->ctrl_index)
	{
	case 3:
		this->openTable(atoi(this->idEdit->getContent()));
		return WAITERWIN;
	case 4:
		return WAITERWIN;
	default:
		return OPENTABLEWIN;
	}
}

int COpenTableWin::openTable(int id)
{
	for(int i=0;i<10;i++)
	{
		if(CTable::arr[i]->getId()==id&&CTable::arr[i]->getStatus()==0)
		{	
			CTable::openingTableId=id;
			CTable::arr[i]->setStatus(1);
			COrder::nowOrder= new COrder(id);
			cout<<"开桌成功"<<endl;
			return 1;
		}
	}
	cout<<"开桌失败"<<endl;
	return 0;
}
