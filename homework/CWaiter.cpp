//
// Created by 1 on 2024/5/22.
//

#include "CWaiter.h"
#include "CWindows.h"
int waiterWin()
{

    int i=0;
    //1.创建窗口结构体
    Win waiter(10,5,80,25);
    //2.创建控件结构体
    Label *title=new Label(40,6,"服务员功能界面");
    Button *button1=new Button(40,9,20,3,"开          桌");
    Button *button2=new Button(40,12,20,3,"点          菜");
    Button *button3=new Button(40,15,20,3,"营 业 额 查 询");
    Button *button4=new Button(40,18,20,3,"已买/未买单查询");
    Button *button5=new Button(40,21,20,3,"修  改  密  码");
    Button *button6=new Button(40,24,20,3,"注          销");
    Button *button7=new Button(40,27,20,3,"退          出");

    //3.把各个控件添加窗口的控件数组中
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