#ifndef _CBUTTON_H_
#define _CBUTTON_H_

#include"CtrlBase.h"

class CButton:public CtrlBase
{
public:
	CButton(int x,int y,int width,int height,char *content);
	~CButton();
	void show();

};
#endif