#ifndef _CWINDOW_H_
#define _CWINDOW_H_

#include"CtrlBase.h"
#include"CButton.h"
#include"CEdit.h"
#include"CLabel.h"
#define ESC -1
#define LOGINWIN 0
#define ADMINWIN 1
#define MANAGERWIN 2
#define WAITERWIN 3
#define REGWIN 4
#define OPENTABLEWIN 5
#define ORDERDISHWIN 6
#define CANCELDISHWIN 7
#define CLOSEBILLWIN 8
/*
#define STAFFMANAGEWIN 6
#define STAFFADDWIN 7
#define STAFFCHECKWIN 8
#define STAFFCHANGEWIN 9
#define TABLEMANAGEWIN 10
#define TABLEADDWIN 11
#define TABLECHECKWIN 12
#define TABLECHANGEWIN 13
#define WAITERPWDMODIFYWIN 14
#define MENUMANAGEWIN 15
#define MENUADDWIN 16
#define MENUSEARCHWIN 17
#define MENUMODIFYWIN 18
#define MENUDELETEWIN 19

*/
//窗口抽象基类
class CWindow{
public:     
	CWindow(int x, int y, int width, int height);
	virtual~CWindow();
	virtual void showWin();	
	void addCtrl(CtrlBase *ctrl);
	void winRun();           //窗口运行
	//父类无公共操作
	virtual int doAction()=0;
protected:
	int x,y;
	int width,height;
	int ctrlCount;
	int ctrl_index;
	CtrlBase *ctrlArr[20];
private:
};





#endif