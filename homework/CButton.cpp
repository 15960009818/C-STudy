#include"CButton.h"
#include"CTools.h"

#include<iostream>
using namespace std;
CButton::CButton(int x,int y,int width,int height ,char*content)
//��ѭ���๹���˳�򣬴��������Ӧ��ֵ
:CtrlBase(x,y,width,height,content,BUTTON)
{

}
CButton::~CButton()
{
	
}

void CButton::show()
{
	CTools::paintWindow(this->x,this->y-1,this->width,this->height);
	CTools::gotoxy(this->x+2,this->y);
	cout<<this->content;
}