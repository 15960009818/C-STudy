//
// Created by 1 on 2024/5/18.
//

#include "CAdmin.h"
#include"CTools.h"
#include "CWindows.h"
int adminWin()
{

    int i=0;
    //1.创建窗口结构体
    Win admin=Win(10,5,80,25);
    //2.创建控件结构体
    addCount *title=new addCount(
            /**x**/40,
            /**y**/8,
            /**width**/0,
            /**height**/0,
            /**ctrlType**/LABEL,
            /**content**/"  管理员界面");
    addCount *button1=new addCount(40,11,20,3,BUTTON,"台桌管理");
    addCount *button2=new addCount(40,14,20,3,BUTTON,"菜谱管理");
    addCount *button3=new addCount(40,17,20,3,BUTTON,"人员管理");
    addCount *button4=new addCount(40,20,20,3,BUTTON,"注    销");
    addCount *button5=new addCount(40,23,20,3,BUTTON,"退    出");
    admin.addCtrl(title);//0
    admin.addCtrl(button1);//1
    admin.addCtrl(button2);//2
    admin.addCtrl(button3);//3
    admin.addCtrl(button4);//4
    admin.addCtrl(button5);//5
    admin.show();
    admin.Run();


    if(admin.ctrl_index==1)
    {
        return TABLEMANAGEWIN;
    }
    if(admin.ctrl_index==2)
    {
        return MENUMANAGEWIN;
    }
    if(admin.ctrl_index==3)
    {
        return STAFFMANAGEWIN;
    }
    if(admin.ctrl_index==5)
    {
        return LOGINWIN;
    }
    return ADMINWIN;
}
