#ifndef _CREGWIN_H_
#define _CREGWIN_H_
#include"CWindow.h"
class CRegWin:public CWindow
{
public:
	CRegWin(int x,int y,int width,int height);
	~CRegWin();
	void showWin();
	int doAction();
private:
	int id;
	CLabel *Label,*idLabel,*idcontent,*userLabel,*pwdLabel,*confirmLabel,*chooseLabel,*roleLabel; 
	CEdit *userEdit,*pwdEdit,*confirmEdit,*roleEdit;
	CButton *regBtn,*escBtn;
};




#endif