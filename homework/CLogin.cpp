#include "CLogin.h"
#include "CWindows.h"
#include "CTools.h"
#include "CStuaff.h" // 修改了头文件名为 CStaff.h

extern CStaff *staffArr[10];
extern int staffCount;
extern int staffIndex;

int loginWin() {
    int key = 0;
    char name[10] = "";
    char pwd[10] = "";

    // 创建窗口结构体
    Win login = Win(10, 5, 80, 25);

    // 创建控件结构体
    addCount *title = new addCount(
            /**x**/40,
            /**y**/7,
            /**width**/0,
            /**height**/0,
            /**ctrlType**/LABEL,
            /**content**/"OrderDish点菜系统");
    addCount *label1 = new addCount(30, 11, 0, 0, LABEL, "用 户 名：");
    addCount *label2 = new addCount(30, 14, 0, 0, LABEL, "密    码：");
    addCount *nameEdit = new addCount(40, 11, 25, 3, EDIT, "", 3,
            /**mode**/1,
            /**makLen**/8);
    addCount *pwdEdit = new addCount(40, 14, 25, 3, EDIT, "", 1, 0, 8);
    addCount *loginBtn = new addCount(30, 21, 7, 3, BUTTON, "登录");
    addCount *escBtn = new addCount(60, 21, 7, 3, BUTTON, "退出");

    // 把各个控件添加窗口的控件数组中
    login.addCtrl(title);    // 0
    login.addCtrl(label1);   // 1
    login.addCtrl(label2);   // 2
    login.addCtrl(nameEdit); // 3
    login.addCtrl(pwdEdit);  // 4
    login.addCtrl(loginBtn); // 5
    login.addCtrl(escBtn);   // 6
    login.show();
    login.Run();

    if (login.ctrl_index == 5) { // 登录
        staffIndex = staffJudge(nameEdit->content, staffArr, staffCount); // 修改了访问 nameEdit 的方式
        return doLogin(staffIndex, pwdEdit->content); // 修改了访问 pwdEdit 的方式
    } else if (login.ctrl_index == 6) { // 退出
        return ESC;
    }
    return LOGINWIN;
}

int staffJudge(const std::string& name, CStaff *staffArr[], int staffCount) { // 修改了参数类型
    for (int i = 0; i < staffCount; i++) {
        if (name == staffArr[i]->name) { // 使用成员函数访问姓名
            return i;
        }
    }
    return -1;
}

int doLogin(int index, const std::string& pwd) { // 修改了参数类型
    if (index == -1) {
        printf("\n用户名不存在\n");
        system("pause");
        return 0;
    }

    if (pwd == staffArr[index]->pwd) { // 使用成员函数访问密码
        printf("\n登陆成功\n");
        switch (staffArr[index]->role) {
            case ADMIN: return 1;
            case MANAGER: return 2;
            case WAITER: return 3;
        }
    } else {
        printf("\n密码错误\n");
        system("pause");
        return 0;
    }

    return 0;
}


