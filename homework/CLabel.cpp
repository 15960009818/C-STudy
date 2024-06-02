#include"CLabel.h"

CLabel::CLabel(int x,int y,int width,int height,char *content)
:CtrlBase(x,y,width,height,content,LABEL)
{

}
CLabel::~CLabel()
{

}
void CLabel::show()
{
	CtrlBase::show();
}

