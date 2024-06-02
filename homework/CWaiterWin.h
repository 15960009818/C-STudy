#ifndef _CWAITERWIN_H_
#define _CWAITERWIN_H_ //∑¿÷π÷ÿ∏¥±‡“Î
#include"CTools.h"
#include "CLabel.h"
#include "CButton.h"
#include "CWindow.h"
//int waiterWin();
class CWaiterWin:public CWindow
{
public:
	CWaiterWin(int x,int y,int width,int height);
	~CWaiterWin();
	int doAction();
private:
	CLabel *title ; 
	CButton *button1,*button2,*button3,*button4,*button5,*button6,*button7;
};
#endif