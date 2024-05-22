#include"CWindows.h"
#include"CTools.h"
#include"CStuaff.h"
extern Staff *staffArr[10];
extern int staffCount;
using namespace std;


CLoginWin::CLoginWin(enum ctrltype ctrlType,int x=0,int y=0,char *content=""){
    memset(this->content,0,sizeof(this->content));
    this->x=x;
    this->y=y;
    this->ctrlType=ctrlType;
    strcpy(this->content,content);
}
CLoginWin::~CLoginWin(){

}
void showWin(){

}
Label::~Label()
{
    cout<<"~Lable"<<endl;
//	delete []this->text;// 释放指针成员
}

int CLoginWin::getX()
{
    return this->x;
}
int CLoginWin::getY()
{
    return this->y;
}
char *CLoginWin::getContent()
{
    return this->content;
}
void CLoginWin::setX(int x)
{
    this->x=x;
}
void CLoginWin::setY(int y)
{
    this->y=y;
}
void CLoginWin::setContent(char *content)
{
    strcpy(this->content,content);
}


void Label::show()
{
    Console::gotoxy(this->x,this->y);
    printf("%s",this->content);
}

Win::Win(int x,int y,int width,int height)
{
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    this->ctrlCount=0;

    for(int i=0;i<20;i++)
    {
        this->ctrlArr[i]=NULL;
    }
}
Win::~Win()
{
    for(int i=0;i<20;i++)
    {
        delete ctrlArr[i];
    }
}


void Win::addCtrl(CLoginWin *ctrl)
{
    this->ctrlArr[this->ctrlCount++]=ctrl;
}
void Win::showWin()
{
    int i=0;
    Console::paintWindow(this->x,this->y,this->width,this->height);

    for(i=0;i<this->ctrlCount;i++)
    {

        switch(this->ctrlArr[i]->ctrlType)
        {
            case LABEL:((Label* )this->ctrlArr[i])->show(); break;
            case EDIT:((Edit* )this->ctrlArr[i])->show(); break;
            case BUTTON:((Button* )this->ctrlArr[i])->show(); break;
        }

    }
}




void Win::winRun()
{
    int i=0,key=0;
    for(i=0;i<this->ctrlCount;i++)
    {
        if(this->ctrlArr[i]->ctrlType==EDIT||this->ctrlArr[i]->ctrlType==BUTTON)
        {
            Console::gotoxy(this->ctrlArr[i]->getX()+2+strlen(this->ctrlArr[i]->getContent()),this->ctrlArr[i]->getY());
            break;
        }
    }

    while(1)
    {
        key=Console::getKey();
        switch(key){
            case Key::UP:
                i--;
                if(i<0) i=this->ctrlCount-1;

                while(1)
                {
                    if(this->ctrlArr[i]->ctrlType==EDIT||this->ctrlArr[i]->ctrlType==BUTTON)
                    {
                        Console::gotoxy(this->ctrlArr[i]->getX()+2+strlen(this->ctrlArr[i]->getContent()),this->ctrlArr[i]->getY());
                        break;
                    }
                    i--;
                    if(i<0) i=this->ctrlCount-1;
                }
                break;
            case Key::DOWN:
                i++;
                if(i>=this->ctrlCount) i=0;
                while(1)
                {
                    if(this->ctrlArr[i]->ctrlType==EDIT||this->ctrlArr[i]->ctrlType==BUTTON)
                    {
                        Console::gotoxy(this->ctrlArr[i]->getX()+2+strlen(this->ctrlArr[i]->getContent()),this->ctrlArr[i]->getY());
                        break;
                    }
                    i++;
                    if(i>=this->ctrlCount) i=0;
                }
                break;
            case Key::ENTER:
                if(this->ctrlArr[i]->ctrlType==BUTTON)
                {
                    this->ctrl_index=i;
                    return;//结束函数
                }
                else if(this->ctrlArr[i]->ctrlType==EDIT)
                {
                    i++;
                    if(i>=this->ctrlCount) i=0;
                    while(1)
                    {
                        if(this->ctrlArr[i]->ctrlType==EDIT||this->ctrlArr[i]->ctrlType==BUTTON)
                        {
                            Console::gotoxy(this->ctrlArr[i]->getX()+2+strlen(this->ctrlArr[i]->getContent()),this->ctrlArr[i]->getY());
                            break;
                        }
                        i++;
                        if(i>=this->ctrlCount) i=0;
                    }
                }
                break;
            default:  //其他非特殊字符
                if(this->ctrlArr[i]->ctrlType==EDIT)
                {
                    ((Edit*)(this->ctrlArr[i]))->editKeyListen((char)key);
                    this->ctrlArr[i]->setContent(((Edit*)(this->ctrlArr[i]))->getContent());
                    if(key<0)
                    {
                        key=Console::getKey();
                        ((Edit*)(this->ctrlArr[i]))->editKeyListen((char)key);
                        this->ctrlArr[i]->setContent(((Edit*)(this->ctrlArr[i]))->getContent());
                    }

                }
                break;
        }
    }



}

void Edit::editKeyListen(char ch)
{

    int len=strlen(this->content);
    if(ch=='\b')
    {
        if(len>0)
        {
            printf("\b \b");
            this->content[--len]='\0';
            if(len>0&&this->content[len-1]<0)
            {
                printf("\b \b");
                this->content[--len]='\0';
                return;
            }
        }


        return;
    }
    if(ch>='0'&&ch<='9'&&(this->inputType==1||this->inputType==3)||
       (ch>='a'&&ch<='z')&&(this->inputType==2||this->inputType==3)||
       (ch>='A'&&ch<='Z')&&(this->inputType==2||this->inputType==3)||
       (ch!='\b'&&ch!='\t')&&(this->inputType==4))
    {
        if(len<this->maxLen)
        {

            putch(this->mode?ch:'*');
            this->content[len]=ch;
            //不用++进入函数自动计算
        }
    }
}