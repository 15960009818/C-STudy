//
// Created by 1 on 2024/5/22.
//

#include "CWaiter.h"
#include "CWindows.h"
int waiterWin()
{

    int i=0;
    //1.�������ڽṹ��
    Win waiter(10,5,80,25);
    //2.�����ؼ��ṹ��
    Label *title=new Label(40,6,"����Ա���ܽ���");
    Button *button1=new Button(40,9,20,3,"��          ��");
    Button *button2=new Button(40,12,20,3,"��          ��");
    Button *button3=new Button(40,15,20,3,"Ӫ ҵ �� �� ѯ");
    Button *button4=new Button(40,18,20,3,"����/δ�򵥲�ѯ");
    Button *button5=new Button(40,21,20,3,"��  ��  ��  ��");
    Button *button6=new Button(40,24,20,3,"ע          ��");
    Button *button7=new Button(40,27,20,3,"��          ��");

    //3.�Ѹ����ؼ���Ӵ��ڵĿؼ�������
    waiter.addCtrl(title);//0
    waiter.addCtrl(button1);//1
    waiter.addCtrl(button2);//2
    waiter.addCtrl(button3);//3
    waiter.addCtrl(button4);//4
    waiter.addCtrl(button5);//5
    waiter.addCtrl(button6);//6
    waiter.addCtrl(button7);//7
    waiter.showWin();
    waiter.winRun();

    if(waiter.ctrl_index==5)
    {
//		return WAITERPWDMODIFYWIN;
    }
    if(waiter.ctrl_index==7)
    {
        return LOGINWIN;
    }
    return WAITERWIN;
}