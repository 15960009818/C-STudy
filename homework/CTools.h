//
// Created by 1 on 2024/5/18.
//

#ifndef CPP_STUDY_TOOLS_H
#define CPP_STUDY_TOOLS_H

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

// Constants for key inputs
namespace Key {
    const int UP = 72;
    const int DOWN = 80;
    const int LEFT = 75;
    const int RIGHT = 77;
    const int ENTER = 13;
    const int ESC = 27;
}

class Console {
public:
    /**
     * 移动光标
     * @param x  x坐标
     * @param y  y坐标
     */
    static void gotoxy(int x, int y);
    /**
     * 按键输入检测,上下左右
     * @return 按键值
     */
    static int getKey();
    /**
     * 生成随机数
     * @param min 最小值
     * @param max 最大值
     * @return
     */
    static int getRandom(int min,int max);
    /**
     * 不同的Label按键会执行不同的功能
     * @param inputType 输入类型（1代表数字，2代表字母，3代表数字和字母）
     * @param maxLen 输入的最大长度
     * @param mode 输入模式（1代表直接显示输入，其他值代表显示为'*'）
     * @param arr 存储输入的字符数组
     * @return
     */
    static int input_check(int inputType,int maxLen,int mode,char *arr);
    /**
     * paintWindow 选择位置绘制表格
     * @param startX 起始x轴
     * @param startY 起始y轴
     * @param width 宽度
     * @param height 高度
     */
    static void paintWindow(int startX,int startY,int width,int height);
    /**
     * 选择位置绘制表格
     * @param x 起始x轴
     * @param y 起始y轴
     * @param col_w 宽度
     * @param row_h 高度
     * @param row 行数
     * @param col 列数
     */
    static void printTable(int x, int y, int col_w, int row_h,int row, int col );

    static int login_check();
};



#endif

