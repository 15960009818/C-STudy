#ifndef _CCANCELDISH_H_
#define _CCANCELDISH_H_
#include"CWindow.h"
#include"COrder.h"
class CCancelDishWin:public CWindow
{
public:
	CCancelDishWin(int x,int y,int width,int height);
	~CCancelDishWin();
	void showWin();
	int doAction();
	void doCancel();
	void doCheck();
private:
	CLabel *Label ,*Label1; 
	CEdit *orderEdit,*menuEdit;
	CButton *confirmBtn,*cancelBtn,*escBtn;
	int i,page,count;
};


#endif