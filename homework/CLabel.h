#ifndef _CLABEL_H_
#define _CLABEL_H_
#include<string.h>
#include<iostream>
#include"CtrlBase.h"
using namespace std;
//��ǩ��
class CLabel:public CtrlBase
{
public:
	CLabel(int x,int y,int width,int height,char *content);
	~CLabel();
	void show();  //  �������Զ��麯��
protected:
private:
};
#endif