//
// Created by 1 on 2024/5/18.
//

#ifndef C_STUDY_TOOLS_H
#define C_STUDY_TOOLS_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27

void gotoxy(int x,int y);
int input_check(int inputType,int maxLen,int mode,char *arr);
void paintWindow(int startX,int startY,int width,int height);
void printTable(int x, int y, int col_w, int row_h,int row, int col );
int login_check();
int getKey();
#endif //C_STUDY_TOOLS_H
