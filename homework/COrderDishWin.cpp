#include"CMenu.h"
#include"CTable.h"

#include"COrderDishWin.h"
COrderDishWin::COrderDishWin(int x,int y,int width,int height)
:CWindow(x,y,width,height)
{
	this->Label=new CLabel(30,8,0,0,"请输入菜品id：");
	this->idEdit=new CEdit(44,8,20,3,"",3,1,8);
	this->orderBtn=new CButton(65,8,7,3,"点菜");
	this->endBtn=new CButton(75,8,12,3,"结束点菜");
	this->escBtn=new CButton(85,8,7,3,"返回");
	this->addCtrl(this->Label);//0
	this->addCtrl(this->idEdit);//1
	this->addCtrl(this->orderBtn);//2
	this->addCtrl(this->endBtn);//3
	this->addCtrl(this->escBtn);//4
	this->i=0;
	this->page=0;
	this->count=0;


}

COrderDishWin::~COrderDishWin()
{
	

}
void COrderDishWin::showWin()
{

	CTools::gotoxy(21,6);
	if(CTable::openingTableId!=-1)
		cout<<"目前正在开桌的id为"<<CTable::openingTableId<<endl;
	else 
	{
		cout<<"您还没开桌，请先开桌后再点菜"<<endl;
		return ;
	}

	CWindow::showWin();
	CTools::printTable(20,10,15,2,5,4 );
	CTools::gotoxy(21,11);
	printf("菜品id");
	CTools::gotoxy(37,11);
	printf("菜品名字"); 
	CTools::gotoxy(53,11);
	printf("菜品信息"); 
	CTools::gotoxy(69,11);
	printf("菜品价格"); 
	CNode *ptmp=CMenu::head->gethead();
	CMenu *pmenu=NULL;
	while(ptmp->pnext!=NULL)
	{
		ptmp=ptmp->pnext;
		pmenu=static_cast<CMenu*>(ptmp->pdata);
		CTools::gotoxy(21,14+count*3);
		printf("%d",pmenu->getId());
		CTools::gotoxy(37,14+count*3);
		printf("%s",pmenu->getName()); 
		CTools::gotoxy(53,14+count*3);
		printf("%s",pmenu->getInfo()); 
		CTools::gotoxy(69,14+count*3);
		printf("%d",pmenu->getPrice()); 
		this->count++;

	}
	this->count=0;
}

int COrderDishWin::doAction()
{ 
	if(CTable::openingTableId==-1)  return WAITERWIN;

	
	switch(this->ctrl_index)
	{
	case 2:
		this->doOrder();
		return ORDERDISHWIN;
	case 3:
		COrder::head->append(COrder::nowOrder);
		CTable::openingTableId=-1;
		return WAITERWIN;
	case 4:
		delete COrder::nowOrder;
		CTable::openingTableId=-1;
		return WAITERWIN;
	default:
		return ORDERDISHWIN;
	}
	return OPENTABLEWIN;
}
void COrderDishWin::doOrder()
{
	int id=atoi(this->idEdit->getContent());
	CMenu *pmenu=CMenu::menuJugde(id);
	if(pmenu==NULL)
	{
		cout<<"该菜品不存在";
		return ;
	}
	int i=COrder::nowOrder->menuJudge(id);
	cout<<i<<endl;
	if(i!=-1)
	{
		COrder::nowOrder->numArr[i]++;
	}
	else
	{
		COrder::nowOrder->arr[COrder::nowOrder->num]=id;
		COrder::nowOrder->numArr[COrder::nowOrder->num++]=1;
		
	}
	COrder::nowOrder->sum+=pmenu->getPrice();
}

