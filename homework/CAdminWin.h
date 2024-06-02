#ifndef _CADMINWIN_H_
#define _CADMINWIN_H_ //∑¿÷π÷ÿ∏¥±‡“Î
#include"CWindow.h"
class CAdminWin:public CWindow
{
public:
	CAdminWin(int x,int y,int width,int height);
	~CAdminWin();
	int doAction();
private:
	CLabel *title ; 
	CButton *button1,*button2,*button3,*button4,*button5;
};
#endif