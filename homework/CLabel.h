#ifndef _CLABEL_H_
#define _CLABEL_H_
#include<string.h>
#include<iostream>
#include"CtrlBase.h"
using namespace std;
//标签类
class CLabel:public CtrlBase
{
public:
	CLabel(int x,int y,int width,int height,char *content);
	~CLabel();
	void show();  //  派生类自动虚函数
protected:
private:
};
#endif