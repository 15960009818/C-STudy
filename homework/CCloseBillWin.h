#ifndef _CCLOSEBILLWIN_H_
#define _CCLOSEBILLWIN_H_
#include"CWindow.h"
class CCloseBillWin:public CWindow
{
public:
	CCloseBillWin(int x,int y,int width,int height);
	~CCloseBillWin();
	int doAction();
private:
	CLabel *title ,*Label; 
	CEdit *idEdit;
	CButton *orderBtn,*escBtn;
};


#endif