#ifndef _CORDERDISHWIN_H_
#define _CORDERDISHWIN_H_
#include"CWindow.h"
#include"COrder.h"
class COrderDishWin:public CWindow
{
public:
	COrderDishWin(int x,int y,int width,int height);
	~COrderDishWin();
	void showWin();
	int doAction();
	void doOrder();
private:
	CLabel *Label ; 
	CEdit *idEdit;
	CButton *orderBtn,*escBtn,*endBtn;
	int i,page,count;

};


#endif