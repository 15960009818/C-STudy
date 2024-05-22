#include"CTools.h"


//���ߺ���ʹ��ʱ����Ҫ��������
/**
     * �ƶ����
     * @param x  x����
     * @param y  y����
     */
void Console:: gotoxy(int x,int y)//�β�
{
    HANDLE hOut;
    COORD pos= {static_cast<SHORT>(x),static_cast<SHORT>(y)};
// ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
//printf("��λ���λ������(%d,%d)\n",pos.X,pos.Y);
}
/**
 * ���������
 * @param min ��Сֵ
 * @param max ���ֵ
 * @return
 */
int Console::getRandom(int min,int max)//rand()%n[0,n-1];
{
    int num=0;
    num=rand()%(max-min+1)+min;
    return num;
}
/**
 * ���������⣬��������
 * @return ����ֵ
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
 * paintWindow ѡ��λ�û��Ʊ��
 * @param startX ��ʼx��
 * @param startY ��ʼy��
 * @param width ���
 * @param height �߶�
 */
void paintWindow(int startX,int startY,int width,int height)
{
    int i=0,j=0;
    int line=0;
    //��һ��
    //���Ͻ�
    Console::gotoxy(startX,startY);
    printf("��");
    for(i=0;i<width-2;i++)
    {
        printf("��");
    }
    printf("��\n");
    line++;
    for(j=0;j<height-2;j++)
    {
        Console::gotoxy(startX,startY+line);
        printf("��");
        for(i=0;i<width-2;i++)
        {
            printf(" ");
        }
        printf("��\n");
        line++;
    }
    Console::gotoxy(startX,startY+line);
    printf("��");
    for(i=0;i<width-2;i++)
    {
        printf("��");
    }
    printf("��\n");

    //���һ��
}
/**
 * ��ͬ��Label������ִ�в�ͬ�Ĺ���
 * @param inputType �������ͣ�1�������֣�2������ĸ��3�������ֺ���ĸ��
 * @param maxLen �������󳤶�
 * @param mode ����ģʽ��1����ֱ����ʾ���룬����ֵ������ʾΪ'*'��
 * @param arr �洢������ַ�����
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
 * ѡ��λ�û��Ʊ��
 * @param x ��ʼx��
 * @param y ��ʼy��
 * @param col_w ���
 * @param row_h �߶�
 * @param row ����
 * @param col ����
 */
void printTable(int x, int y, int col_w, int row_h,int row, int col)
{
    int i=0,j=0,m=0,q=0,line=0;
    Console::gotoxy(x,y);
    //��һ��
    printf("��");
    for(j=0;j<col;j++)
    {
        for(i=0;i<col_w;i++)
        {
            printf("��");
        }
        printf("��");
    }
    printf("\b��\n");
    line++;
    for(m=0;m<row-1;m++)
    {

        for(q=0;q<row_h;q++)
        {
            Console::gotoxy(x,y+line);
            printf("��");
            for(j=0;j<col;j++)
            {
                for(i=0;i<col_w;i++)
                {
                    printf(" ");
                }
                printf("��");
            }
            printf("\n");
            line++;
        }

        Console::gotoxy(x,y+line);
        //�ڶ�����
        printf("��");
        for(j=0;j<col;j++)
        {
            for(i=0;i<col_w;i++)
            {
                printf("��");
            }
            printf("��");
        }
        printf("\b��\n");
        line++;

    }
    //���һ��
    for(q=0;q<row_h;q++)
    {
        Console::gotoxy(x,y+line);
        printf("��");
        for(j=0;j<col;j++)
        {
            for(i=0;i<col_w;i++)
            {
                printf(" ");
            }
            printf("��");
        }
        printf("\n");
        line++;
    }
    Console::gotoxy(x,y+line);
    printf("��");
    //���һ��
    for(j=0;j<col;j++)
    {
        for(i=0;i<col_w;i++)
        {
            printf("��");
        }
        printf("��");
    }
    printf("\b��\n");


}
