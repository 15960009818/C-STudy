#ifndef _CORDER_H_
#define _CORDER_H_ //∑¿÷π÷ÿ∏¥±‡“Î
#include"CTools.h"
#include"CList.h"
class COrder
{
public:
	COrder(int tableId);
	~COrder();
	static COrder *nowOrder;
	int menuJudge(int menuId);
	static int count;
	static CList *head;
	static COrder* orderJudge(int orderId);
	int getId();
	int getStatus();
	int getNum();
//private:
	int id;
	int sum;
	int tableId;
	int num;
	int numArr[20];
	int status;//0 Œ¥Ω·’À  1-“—Ω·’À
	int arr[20];
};


#endif