#ifndef _CLOGINWIN_H_
#define _CLOGINWIN_H_ //∑¿÷π÷ÿ∏¥±‡“Î
#include"CStaff.h"
#include"CWindow.h"
//int «–ªªΩÁ√Ê±‡∫≈

class CLoginWin:public CWindow
{
public:
	CLoginWin(int x,int y,int width,int height);
	~CLoginWin();
	int doAction();
	int doLogin(int index,char *pwd,CStaff *staffArr[]);
private:
	CLabel *title ,*userLabel,*pwdLabel; 
	CEdit *userEdit,*pwdEdit;
	CButton *loginBtn,*regBtn,*escBtn;
};



#endif