#include"CWindows.h"
#include"CTools.h"
#include"CStuaff.h"
extern CStaff *staffArr[10];
extern int staffCount;



addCount::addCount(int x,int y,int width,int height,enum ctrltype ctrlType,char *content,int inputType,int mode,int maxLen)
{
    memset(this->content,0,sizeof(this->content));
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    this->ctrlType=ctrlType;
    strcpy(this->content,content);
    this->inputType=inputType;
    this->mode=mode;
    this->maxLen=maxLen;

}
Win::Win(int x,int y,int width,int height)
{
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    this->ctrlCount=0;
}
Win::~Win()
{
}
void addCount::showLable()
{
    gotoxy(this->x,this->y);
    printf("%s",this->content);
}
void addCount::showEdit()
{
    unsigned int i=0;
    paintWindow(this->x,this->y-1,this->width,this->height);
    gotoxy(this->x+2,this->y);
    if(this->mode==1)
    {
        printf("%s",this->content);
        //
    }
    else if(this->mode==0)
    {
        for(i=0;i<strlen(this->content);i++)
        {
            putch('*');
        }
    }
}
void addCount::showButton()
{
    paintWindow(this->x,this->y-1,this->width,this->height);
    gotoxy(this->x+2,this->y);
    printf("%s",this->content);
}

void Win::addCtrl(addCount *ctrl)
{
    this->ctrlArr[this->ctrlCount++]=ctrl;
}
void Win::show()
{
    int i=0;
    paintWindow(this->x,this->y,this->width,this->height);

    for(i=0;i<this->ctrlCount;i++)
    {

        switch(this->ctrlArr[i]->ctrlType)
        {
            case LABEL:this->ctrlArr[i]->showLable(); break;
            case EDIT:this->ctrlArr[i]->showEdit(); break;
            case BUTTON:this->ctrlArr[i]->showButton(); break;
        }

    }
}




void Win::Run()
{

    int i=0,key=0;
    for(i=0;i<this->ctrlCount;i++)
    {
        if(this->ctrlArr[i]->ctrlType==EDIT||this->ctrlArr[i]->ctrlType==BUTTON)
        {
            gotoxy(this->ctrlArr[i]->x+2+strlen(this->ctrlArr[i]->content),this->ctrlArr[i]->y);
            break;
        }
    }

    while(1)
    {
        key=getKey();
        switch(key){
            case KEY_UP:
                i--;
                if(i<0) i=this->ctrlCount-1;

                while(1)
                {
                    if(this->ctrlArr[i]->ctrlType==EDIT||this->ctrlArr[i]->ctrlType==BUTTON)
                    {
                        gotoxy(this->ctrlArr[i]->x+2+strlen(this->ctrlArr[i]->content),this->ctrlArr[i]->y);
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
                    if(this->ctrlArr[i]->ctrlType==EDIT||this->ctrlArr[i]->ctrlType==BUTTON)
                    {
                        gotoxy(this->ctrlArr[i]->x+2+strlen(this->ctrlArr[i]->content),this->ctrlArr[i]->y);
                        break;
                    }
                    i++;
                    if(i>=this->ctrlCount) i=0;
                }
                break;
            case KEY_ENTER:
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
                            gotoxy(this->ctrlArr[i]->x+2+strlen(this->ctrlArr[i]->content),this->ctrlArr[i]->y);
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

                    this->ctrlArr[i]->editKeyListen((char)key);
                    if(key<0)
                    {
                        key=getKey();
                        this->ctrlArr[i]->editKeyListen((char)key);
                    }

                }
                break;
        }
    }



}

void addCount::editKeyListen(char ch)
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
            ;
            putch(this->mode?ch:'*');
            this->content[len]=ch;
            //不用++进入函数自动计算
        }
    }
}
