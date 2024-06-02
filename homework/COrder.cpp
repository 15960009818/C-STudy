#include"COrder.h"
int COrder::count=0;
CList *COrder::head=new CList();
COrder* COrder::nowOrder=NULL;
COrder::COrder(int tableId)
{
	this->id=1001+COrder::count;
	COrder::count++;
	this->sum=0;
	this->num=0;
	this->status=0;
	this->tableId=tableId;
	memset(this->arr,0,sizeof(this->arr));
	memset(this->numArr,0,sizeof(this->numArr));
}

COrder::~COrder()
{
}
int COrder::menuJudge(int menuId)
{
	for(int i=0;i<this->num;i++)
	{
		if(this->arr[i]==menuId)
		{
			return i;
		}
	}
	
	return -1;
}


int COrder::getId()
{
	return this->id;
}
int COrder::getStatus()
{
	return this->status;
}


COrder* COrder::orderJudge(int orderId)
{
	CNode *ptmp=COrder::head->gethead();
	COrder *porder=NULL;
	while(ptmp->pnext!=NULL)
	{
		ptmp=ptmp->pnext;
		porder=static_cast<COrder*>(ptmp->pdata);
		if(porder->id==orderId)
		{
			return porder;
		}
	}
	return NULL;
}