#include"CTools.h"


void CTools::string2char(char *s,string str)
{
	strcpy(s,str.c_str());

}
int CTools::string2int(string str)
{
	char s[100];
	strcpy(s,str.c_str());
	return atoi(s);
}
string CTools::int2string(int num)
{
	char s[100];
	sprintf(s,"%d",num);
	string str;
	str=s;
	return str;
}
void CTools::gotoxy(int x,int y)//形参
{
    HANDLE hOut;
	COORD pos= {static_cast<SHORT>(x),static_cast<SHORT>(y)};
// 光标的起始位（第1列，第3行） 0是第1列 2是第3行
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos); 
//printf("定位光标位置搜索(%d,%d)\n",pos.X,pos.Y);
}
int CTools::getRandom(int a,int b)//rand()%n[0,n-1];
{
	int num=0;
	num=rand()%(b-a+1)+a;
	return num;
}


void CTools::paintWindow(int startX,int startY,int width,int height)
{
	int i=0,j=0;
	int line=0;
	//第一行
	//左上角
	gotoxy(startX,startY);
	printf("┌");
	for(i=0;i<width-2;i++)
	{
		printf("─");
	}
	printf("┐\n");
	line++;
	for(j=0;j<height-2;j++)
	{
		gotoxy(startX,startY+line);
		printf("│");
		for(i=0;i<width-2;i++)
		{
			printf(" ");
		}
		printf("│\n");
		line++;
	}
	gotoxy(startX,startY+line);
	printf("└");
	for(i=0;i<width-2;i++)
	{
		printf("─");
	}
	printf("┘\n");

	//最后一行
}

int CTools::input_check(int inputType,int maxLen,int mode,char *arr)
{
	int ch;
	int i=0;
	while(1)
	{
		ch=getKey();
		if(ch==KEY_UP||ch==KEY_DOWN) return ch;
		if(ch>='0'&&ch<='9'&&(inputType==1||inputType==3)||
			(ch>='a'&&ch<='z')&&(inputType==2||inputType==3)||
			(ch>='A'&&ch<='Z')&&(inputType==2||inputType==3))
		{
			if(i<maxLen)
			{
				putch(mode?ch:'*');
				arr[i]=ch;
				i++;
			}
		}

		else if(ch == '\b'&&i>0)
		{
			printf("\b \b");
			arr[--i]='\0';
		}
		else if(ch=='\r')
		{
			break;
		}
	}
	printf("\t%s",arr);
	return KEY_ENTER;

}
int CTools::getKey()
{
	char key=0;
	key=getch();
	if(key == -32||key==224)
	{
		key=getch();
		switch(key)
		{
		case 72:return KEY_UP;
		case 75:return KEY_LEFT;
		case 77:return KEY_RIGHT;
		case 80:return KEY_DOWN;
		}
	}
	else if (key == 13)
	{
		return KEY_ENTER;
	}
	else if (key == 27)
	{
		return KEY_ESC;
	}	
	return key;
}
void CTools::printTable(int x, int y, int col_w, int row_h,int row, int col)
{
	int i=0,j=0,m=0,q=0,line=0;
	gotoxy(x,y);
	//第一行
	printf("┌");
	for(j=0;j<col;j++)
	{
		for(i=0;i<col_w;i++)
		{
			printf("─");
		}
		printf("┬");
	}
	printf("\b┐\n");
	line++;
	for(m=0;m<row-1;m++)
	{

		for(q=0;q<row_h;q++)
		{
			gotoxy(x,y+line);
			printf("│");
			for(j=0;j<col;j++)
			{
				for(i=0;i<col_w;i++)
				{
					printf(" ");
				}
				printf("│");
			}
			printf("\n");
			line++;
		}
		
		gotoxy(x,y+line);
		//第二部分
		printf("├");
		for(j=0;j<col;j++)
		{
			for(i=0;i<col_w;i++)
			{
				printf("─");
			}
			printf("┼");
		}
		printf("\b┤\n");
		line++;

	}
	//最后一行
	for(q=0;q<row_h;q++)
	{
		gotoxy(x,y+line);
		printf("│");
		for(j=0;j<col;j++)
		{
			for(i=0;i<col_w;i++)
			{
				printf(" ");
			}
			printf("│");
		}
		printf("\n");
		line++;
	}
	gotoxy(x,y+line);
	printf("└");
	//最后一行
	for(j=0;j<col;j++)
	{
		for(i=0;i<col_w;i++)
		{
			printf("─");
		}
		printf("┴");
	}
	printf("\b┘\n");


}
