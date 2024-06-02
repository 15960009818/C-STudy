#include"CButton.h"
#include"CTools.h"

#include<iostream>
using namespace std;
CButton::CButton(int x,int y,int width,int height ,char*content)
//遵循父类构造的顺序，传入子类对应的值
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