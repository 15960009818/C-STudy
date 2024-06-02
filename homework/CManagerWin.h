#ifndef _CMANAGERWIN_H_
#define _CMANAGERWIN_H_ //∑¿÷π÷ÿ∏¥±‡“Î
#include"CWindow.h"
//int managerWin();
class CManagerWin:public CWindow
{
public:
	CManagerWin(int x,int y,int width,int height);
	~CManagerWin();
	int doAction();
private:
	CLabel *title ; 
	CButton *button1,*button2,*button3;
};
#endif