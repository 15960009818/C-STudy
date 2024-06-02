#include"CtrlBase.h"
#include"CTools.h"
#include<string.h>
#include<iostream>
using namespace std;
CtrlBase::CtrlBase(int x,int y,int width,int height,char *content,enum CtrlType ctrlType)
{
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	memset(this->content,0,sizeof(this->content));
	strcpy(this->content,content);
	this->ctrlType=ctrlType;
}
CtrlBase::~CtrlBase()
{
}

void CtrlBase::editKeyListen(int ch)
{

}
int CtrlBase::getX()
{
	return this->x;
}
int CtrlBase::getY()
{
	return this->y;
}
int CtrlBase::getWidth()
{
	return this->width;
}
int CtrlBase::getHeight()
{
	return this->height;
}
char *CtrlBase::getContent()
{
	return this->content;
}
enum CtrlType CtrlBase::getType()
{
	return this->ctrlType;
}
void CtrlBase::setX(int x)
{
	this->x=x;
}
void CtrlBase::setY(int y)
{
	this->y=y;
}
void CtrlBase::setWidth(int width)
{
	this->width=width;
}
void CtrlBase::setHeight(int height)
{
	this->height=height;
}
void CtrlBase::setContent(char *content)
{
	strcpy(this->content,content);
}
void CtrlBase::setType(enum CtrlType ctrlType)
{
	this->ctrlType=ctrlType;
}
void CtrlBase::show()
{
	CTools::gotoxy(this->x,this->y);
	cout<<this->content;
}
