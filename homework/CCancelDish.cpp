#include"CMenu.h"
#include"CTable.h"
#include"COrder.h"
#include"CCancelDish.h"
CCancelDishWin::CCancelDishWin(int x,int y,int width,int height)
:CWindow(x,y,width,height)
{
	this->Label=new CLabel(30,8,0,0,"请输入退菜订单id：");
	this->Label1=new CLabel(30,11,0,0,"请输入退菜菜品id：");
	this->orderEdit=new CEdit(44,8,20,3,"",3,1,8);
	this->menuEdit=new CEdit(44,11,20,3,"",3,1,8);
	this->confirmBtn=new CButton(65,8,7,3,"确认");
	this->cancelBtn=new CButton(65,11,7,3,"退菜");
	this->escBtn=new CButton(85,8,7,3,"返回");
	this->addCtrl(this->Label);//0
	this->addCtrl(this->Label1);//1
	this->addCtrl(this->orderEdit);//2
	this->addCtrl(this->menuEdit);//3
	this->addCtrl(this->confirmBtn);//4
	this->addCtrl(this->cancelBtn);//5
	this->addCtrl(this->escBtn);//6
	this->i=0;
	this->page=0;
	this->count=0;

}

CCancelDishWin::~CCancelDishWin()
{

}
void CCancelDishWin::showWin()
{
	CWindow::showWin();
	CTools::printTable(20,13,15,2,5,4 );
	CTools::gotoxy(21,14);
	printf("菜品id");
	CTools::gotoxy(37,14);
	printf("菜品名字"); 
	CTools::gotoxy(53,14);
	printf("菜品个数"); 
	CTools::gotoxy(69,14);
	printf("菜品价格"); 
	if(strcmp(this->orderEdit->getContent(),"")!=0)
	{
		cout<<this->orderEdit->getContent()<<endl;
		int orderId=atoi(this->orderEdit->getContent());
		COrder *porder=COrder::orderJudge(orderId);
		for(int i=0;i<(porder->num>4?4:porder->num);i++)
		{
			CMenu *pmenu=CMenu::menuJugde(porder->arr[i]);
			CTools::gotoxy(21,17+count*3);
			printf("%d",porder->arr[i]);
			CTools::gotoxy(37,17+count*3);
			printf("%s",pmenu->getName()); 
			CTools::gotoxy(53,17+count*3);
			printf("%d",porder->numArr[i]); 
			CTools::gotoxy(69,17+count*3);
			printf("%d",pmenu->getPrice()); 
			this->count++;
		}
	}
	this->count=0;
}

int CCancelDishWin::doAction()
{ 	
	switch(this->ctrl_index)
	{
	case 4:
		this->doCheck();
		return CANCELDISHWIN;
	case 5:
		this->doCancel();
		return CANCELDISHWIN;
	case 6:
		return WAITERWIN;
	default:
		return CANCELDISHWIN;
	}
	return OPENTABLEWIN;
}
void CCancelDishWin::doCheck()
{
	int orderId=atoi(this->orderEdit->getContent());
	COrder *porder=COrder::orderJudge(orderId);
	if(porder==NULL) 
	{
		cout<<"不存在该订单"<<endl;
		this->orderEdit->setContent("");
		return ;
	}
	if(porder!=NULL&&porder->status==1)
	{
		cout<<"该订单已结束"<<endl;
		this->orderEdit->setContent("");
		return;
	}
	return ;
	
}
void CCancelDishWin::doCancel()
{
	if(strcmp(this->orderEdit->getContent(),"")==0||strcmp(this->orderEdit->getContent(),"")==0) 
	{
		cout<<"id不可为空";
		return;
	}
	int orderId=atoi(this->orderEdit->getContent());
	int menuId=atoi(this->menuEdit->getContent());
	
	COrder *porder=COrder::orderJudge(orderId);
	if(porder==NULL) 
	{
		cout<<"不存在该订单"<<endl;
		return ;
	}
	if(porder!=NULL&&porder->status==1)
	{
		cout<<"该订单已结束"<<endl;
		return ;
	}
	int i=porder->menuJudge(menuId);
	if(i==-1) 
	{
		cout<<"该菜品不在订单内"<<endl;
		return ;
	}
	if(porder->numArr[i]>0)
	{
		porder->numArr[i]--;
		cout<<"退菜成功";
	}
	else 
	{
		cout<<"该菜品已经退掉了"<<endl;
	}
	

}

