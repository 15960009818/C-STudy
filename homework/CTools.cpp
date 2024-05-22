#include"CTools.h"


//工具函数使用时不需要创建对象
/**
     * 移动光标
     * @param x  x坐标
     * @param y  y坐标
     */
void Console:: gotoxy(int x,int y)//形参
{
    HANDLE hOut;
    COORD pos= {static_cast<SHORT>(x),static_cast<SHORT>(y)};
// 光标的起始位（第1列，第3行） 0是第1列 2是第3行
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
//printf("定位光标位置搜索(%d,%d)\n",pos.X,pos.Y);
}
/**
 * 生成随机数
 * @param min 最小值
 * @param max 最大值
 * @return
 */
int Console::getRandom(int min,int max)//rand()%n[0,n-1];
{
    int num=0;
    num=rand()%(max-min+1)+min;
    return num;
}
/**
 * 按键输入检测，上下左右
 * @return 按键值
 */
int Console::getKey()
{
    char key=0;
    key=getch();
    if(key == -32||key==224)
    {
        key=getch();
        switch(key)
        {
            case 72:return Key::UP;
            case 75:return Key::LEFT;
            case 77:return Key::RIGHT;
            case 80:return Key::DOWN;
        }
    }
    else if (key == 13)
    {
        return Key::ENTER;
    }
    else if (key == 27)
    {
        return Key::ESC;
    }
    return key;
}
/**
 * paintWindow 选择位置绘制表格
 * @param startX 起始x轴
 * @param startY 起始y轴
 * @param width 宽度
 * @param height 高度
 */
void paintWindow(int startX,int startY,int width,int height)
{
    int i=0,j=0;
    int line=0;
    //第一行
    //左上角
    Console::gotoxy(startX,startY);
    printf("┌");
    for(i=0;i<width-2;i++)
    {
        printf("─");
    }
    printf("┐\n");
    line++;
    for(j=0;j<height-2;j++)
    {
        Console::gotoxy(startX,startY+line);
        printf("│");
        for(i=0;i<width-2;i++)
        {
            printf(" ");
        }
        printf("│\n");
        line++;
    }
    Console::gotoxy(startX,startY+line);
    printf("└");
    for(i=0;i<width-2;i++)
    {
        printf("─");
    }
    printf("┘\n");

    //最后一行
}
/**
 * 不同的Label按键会执行不同的功能
 * @param inputType 输入类型（1代表数字，2代表字母，3代表数字和字母）
 * @param maxLen 输入的最大长度
 * @param mode 输入模式（1代表直接显示输入，其他值代表显示为'*'）
 * @param arr 存储输入的字符数组
 * @return
 */
int input_check(int inputType,int maxLen,int mode,char *arr)
{
    int ch;
    int i=0;
    while(1)
    {
        ch=Console::getKey();
        if(ch==Key::UP||ch==Key::DOWN) return ch;
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
    return Key::ENTER;

}
/**
 * 选择位置绘制表格
 * @param x 起始x轴
 * @param y 起始y轴
 * @param col_w 宽度
 * @param row_h 高度
 * @param row 行数
 * @param col 列数
 */
void printTable(int x, int y, int col_w, int row_h,int row, int col)
{
    int i=0,j=0,m=0,q=0,line=0;
    Console::gotoxy(x,y);
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
            Console::gotoxy(x,y+line);
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

        Console::gotoxy(x,y+line);
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
        Console::gotoxy(x,y+line);
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
    Console::gotoxy(x,y+line);
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
