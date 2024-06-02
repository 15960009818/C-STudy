#ifndef _CTOOLS_H_
#define _CTOOLS_H_

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define KEY_UP 172
#define KEY_DOWN 180
#define KEY_LEFT 175
#define KEY_RIGHT 177
#define KEY_ENTER 13
#define KEY_ESC 27

class CTools
{
public:

void string2char(char *s,string str);
static int string2int(string s);
static string int2string(int num);

static void gotoxy(int x,int y);

static int getRandom(int a,int b);

static int input_check(int inputType,int maxLen,int mode,char *arr);

static void paintWindow(int startX,int startY,int width,int height);
static void printTable(int x, int y, int col_w, int row_h,int row, int col );
static int login_check();
static int getKey();
};
#endif