#ifndef _COPENTABLEWIN_H_
#define _COPENTABLEWIN_H_
#include"CWindow.h"
class COpenTableWin:public CWindow
{
public:
	COpenTableWin(int x,int y,int width,int height);
	~COpenTableWin();
	int doAction();
	int openTable(int id);
private:
	CLabel *title ,*Label; 
	CEdit *idEdit;
	CButton *orderBtn,*escBtn;
};


#endif