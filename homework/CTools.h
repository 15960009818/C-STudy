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
    static void gotoxy(int x, int y);
    static int getKey();
};

class Input {
public:
    Input(int type, int maxLength, int mode, const std::string& input)
            : inputType(type), maxLen(maxLength), mode(mode), inputStr(input) {}

    int check();

private:
    int inputType;
    int maxLen;
    int mode;
    std::string inputStr;
};

class Window {
public:
    Window(int startX, int startY, int width, int height)
            : startX(startX), startY(startY), width(width), height(height) {}

    void paint();

private:
    int startX;
    int startY;
    int width;
    int height;
};

class Table {
public:
    Table(int x, int y, int colWidth, int rowHeight, int rows, int cols)
            : x(x), y(y), colWidth(colWidth), rowHeight(rowHeight), rows(rows), cols(cols) {}

    void print();

private:
    int x;
    int y;
    int colWidth;
    int rowHeight;
    int rows;
    int cols;
};

class Authentication {
public:
    static int loginCheck();
};

#endif

