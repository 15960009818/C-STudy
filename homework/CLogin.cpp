#include "CLogin.h"
#include "CWindows.h"
#include "CTools.h"
#include "CStuaff.h" // �޸���ͷ�ļ���Ϊ CStaff.h

extern CStaff *staffArr[10];
extern int staffCount;
extern int staffIndex;

int loginWin() {
    int key = 0;
    char name[10] = "";
    char pwd[10] = "";

    // �������ڽṹ��
    Win login = Win(10, 5, 80, 25);

    // �����ؼ��ṹ��
    addCount *title = new addCount(
            /**x**/40,
            /**y**/7,
            /**width**/0,
            /**height**/0,
            /**ctrlType**/LABEL,
            /**content**/"OrderDish���ϵͳ");
    addCount *label1 = new addCount(30, 11, 0, 0, LABEL, "�� �� ����");
    addCount *label2 = new addCount(30, 14, 0, 0, LABEL, "��    �룺");
    addCount *nameEdit = new addCount(40, 11, 25, 3, EDIT, "", 3,
            /**mode**/1,
            /**makLen**/8);
    addCount *pwdEdit = new addCount(40, 14, 25, 3, EDIT, "", 1, 0, 8);
    addCount *loginBtn = new addCount(30, 21, 7, 3, BUTTON, "��¼");
    addCount *escBtn = new addCount(60, 21, 7, 3, BUTTON, "�˳�");

    // �Ѹ����ؼ���Ӵ��ڵĿؼ�������
    login.addCtrl(title);    // 0
    login.addCtrl(label1);   // 1
    login.addCtrl(label2);   // 2
    login.addCtrl(nameEdit); // 3
    login.addCtrl(pwdEdit);  // 4
    login.addCtrl(loginBtn); // 5
    login.addCtrl(escBtn);   // 6
    login.show();
    login.Run();

    if (login.ctrl_index == 5) { // ��¼
        staffIndex = staffJudge(nameEdit->content, staffArr, staffCount); // �޸��˷��� nameEdit �ķ�ʽ
        return doLogin(staffIndex, pwdEdit->content); // �޸��˷��� pwdEdit �ķ�ʽ
    } else if (login.ctrl_index == 6) { // �˳�
        return ESC;
    }
    return LOGINWIN;
}

int staffJudge(const std::string& name, CStaff *staffArr[], int staffCount) { // �޸��˲�������
    for (int i = 0; i < staffCount; i++) {
        if (name == staffArr[i]->name) { // ʹ�ó�Ա������������
            return i;
        }
    }
    return -1;
}

int doLogin(int index, const std::string& pwd) { // �޸��˲�������
    if (index == -1) {
        printf("\n�û���������\n");
        system("pause");
        return 0;
    }

    if (pwd == staffArr[index]->pwd) { // ʹ�ó�Ա������������
        printf("\n��½�ɹ�\n");
        switch (staffArr[index]->role) {
            case ADMIN: return 1;
            case MANAGER: return 2;
            case WAITER: return 3;
        }
    } else {
        printf("\n�������\n");
        system("pause");
        return 0;
    }

    return 0;
}


