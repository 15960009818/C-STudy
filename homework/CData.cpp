#include"CData.h"
#include <iostream>
#include <fstream>
#include <string>
#include "CStaff.h"
#include "list"
using namespace std;

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
        staffList.push_back(new CStaff( 1001,"aaa","123456", ADMIN));
        staffList.push_back(new CStaff(1002,"bbb","123456", MANAGER));

        list<CStaff *>::iterator it; // 指针指向元素的地址
        for (it = CData::staffList.begin(); it != CData::staffList.end(); ++it) {
            cout << (*it)->getId() << "," << (*it)->getPwd() << "," << (*it)->getRole() << endl;
            fs << (*it)->getId() << "," << (*it)->getPwd() << "," << (*it)->getRole() << endl;
        }
    }
        else {
            char buf[256] = {0};
            int id = 0,role = 0;
            char name[10];
            char  pwd[10];
            cout << "有数据" << endl;
            // 逐行读取 -> 列表容器
            while (fs.peek() != EOF) {
                fs.getline(buf, 255);
                cout << buf << endl;
                sscanf(buf,"%d %s %s %d", &id,name,pwd,&role);
                cout<<id<<"-"<<endl;
                staffList.push_back(new CStaff(id,name,pwd,role));
            }
        // 创建迭代器
        list<CStaff*>::iterator it; // 指针指向元素的地址
        for (it = staffList.begin(); it != staffList.end(); ++it) {
            fs << (*it)->getId() << "," << (*it)->getName() << "," << (*it)->getPwd() << "," << (*it)->getRole() << endl;
        }

// 关闭文件
        fs.close();
        }

    // 关闭文件
    fs.close();
}
