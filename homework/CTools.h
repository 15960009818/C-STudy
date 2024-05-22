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
     * �ƶ����
     * @param x  x����
     * @param y  y����
     */
    static void gotoxy(int x, int y);
    /**
     * ����������,��������
     * @return ����ֵ
     */
    static int getKey();
    /**
     * ���������
     * @param min ��Сֵ
     * @param max ���ֵ
     * @return
     */
    static int getRandom(int min,int max);
    /**
     * ��ͬ��Label������ִ�в�ͬ�Ĺ���
     * @param inputType �������ͣ�1�������֣�2������ĸ��3�������ֺ���ĸ��
     * @param maxLen �������󳤶�
     * @param mode ����ģʽ��1����ֱ����ʾ���룬����ֵ������ʾΪ'*'��
     * @param arr �洢������ַ�����
     * @return
     */
    static int input_check(int inputType,int maxLen,int mode,char *arr);
    /**
     * paintWindow ѡ��λ�û��Ʊ��
     * @param startX ��ʼx��
     * @param startY ��ʼy��
     * @param width ���
     * @param height �߶�
     */
    static void paintWindow(int startX,int startY,int width,int height);
    /**
     * ѡ��λ�û��Ʊ��
     * @param x ��ʼx��
     * @param y ��ʼy��
     * @param col_w ���
     * @param row_h �߶�
     * @param row ����
     * @param col ����
     */
    static void printTable(int x, int y, int col_w, int row_h,int row, int col );

    static int login_check();
};



#endif

