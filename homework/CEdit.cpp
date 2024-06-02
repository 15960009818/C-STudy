#include"CEdit.h"
#include"CTools.h"
#include<iostream>
using namespace std;

CEdit::CEdit(int x,int y,int width,int height ,char*content ,int inputType,int mode,int maxLen)
:CtrlBase(x,y,width,height,content,EDIT)
{
	this->inputType=inputType;
	this->maxLen=maxLen;
	this->mode=mode;
}
CEdit::~CEdit()
{
}

int CEdit::getInputType()
{
	return this->inputType;
}
int CEdit::getMaxLen()
{
	return this->maxLen;
}
int CEdit::getMode()
{
	return this->mode;
}

void CEdit::setInputType(int inputType)
{
	this->inputType=inputType;
}
void CEdit::setMaxLen(int maxLen)
{
	this->maxLen=maxLen;
}
void CEdit::setMode(int mode)
{
	this->mode=mode;
}

void CEdit::show()
{
	unsigned int i=0;
	CTools::paintWindow(this->x,this->y-1,this->width,this->height);
	CTools::gotoxy(this->x+2,this->y);
	if(this->mode==1)
	{
		cout<<this->content;
		//
	}
	else if(this->mode==0)
	{
		for(i=0;i<strlen(this->content);i++)
		{
			cout<<'*';
		}
	}
}

void CEdit::editKeyListen(int ch)
{
	int len=strlen(this->content);
	int cnflag=0;
	if(ch=='\b')
	{
		if(len>0)
		{
			printf("\b \b");
			if((unsigned char)(this->content[len-1])>=0xA1&&(unsigned char)(this->content[len-1])<=0xFE) cnflag=1;
			this->content[--len]='\0';
			if(len>0&&cnflag)
			{
				printf("\b \b");
				this->content[--len]='\0';
				return;
			}
		}
	

		return;
	}
	if(ch>='0'&&ch<='9'&&(this->inputType==1||this->inputType==3||this->inputType==4)||
		(ch>='a'&&ch<='z')&&(this->inputType==2||this->inputType==3||this->inputType==4)||
		(ch>='A'&&ch<='Z')&&(this->inputType==2||this->inputType==3||this->inputType==4)
		)
	{
		if(len<this->maxLen)
		{
			
			putch(this->mode?ch:'*');
			this->content[len]=ch;
		}
	}
	else if(this->inputType==4) //ÖÐÎÄ
	{
		if((unsigned char) ch>=0xA1&&(unsigned char) ch<=0xFE)
		{
			char ch2=getch();
			if((unsigned char) ch>=0xA1&&(unsigned char) ch<=0xFE)
			{
				if(len<this->maxLen)
				{
					
					putch(this->mode?ch:'*');
					putch(this->mode?ch2:'*');
					this->content[len]=ch;
					this->content[len+1]=ch2;
				}

			}
		}
	}
}