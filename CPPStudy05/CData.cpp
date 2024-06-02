#include"CData.h"
#include <iostream>
#include <fstream>
#include <string>
#include "CStaff.h"
#include "list"
using namespace std;

// 定义静态成员变量
list<CStaff*> CData::staffList;

void CData::staffInit() {
    // 创建文件对象
    fstream fs;

    // 以读写方式打开文件，并且文件尾部追加
    fs.open("data/staff.txt", ios_base::in | ios_base::out | ios_base::app);

    // 判断文件是否成功打开
    if (!fs.is_open()) {
        cerr << "无法打开文件" << endl;
        return;
    }

    // 定位到文件末尾
    fs.seekg(0, ios_base::end);
    streampos num = fs.tellg();
    cout << (int)num << endl;

    if ((int)num <= 0) {
        // 文件无数据
        cout << "无数据" << endl;

        // 尾部追加数据
        staffList.push_back(new CStaff(1001, "admin", "123456", ADMIN));
        staffList.push_back(new CStaff(1002, "manager", "123456", MANAGER));

        // 同步数据到文件
        syncStaffData();
    } else {
        char buf[256] = {0};
        cout << "有数据" << endl;
        // 逐行读取 -> 列表容器
        while (fs.peek() != EOF) {
            fs.getline(buf, 255);
            cout << buf << endl;
        }
    }

    // 关闭文件
    fs.close();
}

void CData::syncStaffData() {
    // 创建文件对象
    fstream fs;

    // 以写方式打开文件，覆盖现有内容
    fs.open("data/staff.txt", ios_base::out | ios_base::trunc);

    if (!fs.is_open()) {
        cerr << "无法打开文件进行写入" << endl;
        return;
    }

    // 逐行写入staffList中的数据
    list<CStaff*>::iterator it; // 指针指向元素的地址
    for (it = staffList.begin(); it != staffList.end(); ++it) {
        fs << (*it)->getId() << "," << (*it)->getName() << "," << (*it)->getPwd() << "," << (*it)->getRole() << endl;
    }

    // 关闭文件
    fs.close();
}