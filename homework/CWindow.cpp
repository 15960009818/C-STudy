#include"CWindow.h"
#include"CEdit.h"
#include"CLabel.h"
#include"CButton.h"
#include"CtrlBase.h"
#include"CTools.h"
CWindow::CWindow(int x, int y, int width, int height){
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	this->ctrlCount=0;
	this->ctrl_index=-1;
	for(int i=0;i<20;i++){
		this->ctrlArr[i]=NULL;
	}

}
CWindow::~CWindow()
{
	for(int i=0;i<this->ctrlCount;i++)
	{
		delete this->ctrlArr[i];
	}

}

void CWindow::showWin(){
	//窗口显示
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	//各控件显示
	for(int i=0;i<this->ctrlCount;i++)
	{//基类指针调用虚函数show()  基类指针自动指向派生类指针
			this->ctrlArr[i]->show();
	}
}	

void CWindow::addCtrl(CtrlBase*ctrl){
	this->ctrlArr[this->ctrlCount++]=ctrl;
}
void CWindow::winRun(){
	int i=0,key=0;
	for(i=0;i<this->ctrlCount;i++)
	{
		if(this->ctrlArr[i]->getType()==EDIT||this->ctrlArr[i]->getType()==BUTTON)
		{
			CTools::gotoxy(this->ctrlArr[i]->getX()+2+strlen(this->ctrlArr[i]->getContent()),this->ctrlArr[i]->getY());
			break;
		}
	}

	while(1)
	{
		key=CTools::getKey();
		switch(key){
		case KEY_UP:
			i--;
			if(i<0) i=this->ctrlCount-1;

			while(1)
			{
				if(this->ctrlArr[i]->getType()==EDIT||this->ctrlArr[i]->getType()==BUTTON)
				{
					CTools::gotoxy(this->ctrlArr[i]->getX()+2+strlen(this->ctrlArr[i]->getContent()),this->ctrlArr[i]->getY());
					break;
				}
				i--;
				if(i<0) i=this->ctrlCount-1;
			}
			break;
		case KEY_DOWN:
			i++;
			if(i>=this->ctrlCount) i=0;
			while(1)
			{
				if(this->ctrlArr[i]->getType()==EDIT||this->ctrlArr[i]->getType()==BUTTON)
				{
					CTools::gotoxy(this->ctrlArr[i]->getX()+2+strlen(this->ctrlArr[i]->getContent()),this->ctrlArr[i]->getY());
					break;
				}
				i++;
				if(i>=this->ctrlCount) i=0;
			}
			break;
		case KEY_ENTER:
			if(this->ctrlArr[i]->getType()==BUTTON)
			{
				this->ctrl_index=i;
				return;//结束函数
			}
			else if(this->ctrlArr[i]->getType()==EDIT)
			{
				i++;
				if(i>=this->ctrlCount) i=0;
				while(1)
				{
					if(this->ctrlArr[i]->getType()==EDIT||this->ctrlArr[i]->getType()==BUTTON)
					{
						CTools::gotoxy(this->ctrlArr[i]->getX()+2+strlen(this->ctrlArr[i]->getContent()),this->ctrlArr[i]->getY());
						break;
					}
					i++;
					if(i>=this->ctrlCount) i=0;
				}
			}
			break;
		default:  //其他非特殊字符
			if(this->ctrlArr[i]->getType()==EDIT)
			{

				this->ctrlArr[i]->editKeyListen((char)key);

			}
			break;
		}
	}

}

