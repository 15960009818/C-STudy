#include"CData.h"
#include <iostream>
#include <fstream>
#include <string>
#include "CStaff.h"
#include "list"
using namespace std;

void CData::staffInit() {
    // �����ļ�����
    fstream fs;

    // �Զ�д��ʽ���ļ��������ļ�β��׷��
    fs.open("data/staff.txt", ios_base::in | ios_base::out | ios_base::app);

    // �ж��ļ��Ƿ�ɹ���
    if (!fs.is_open()) {
        cerr << "�޷����ļ�" << endl;
        return;
    }

    // ��λ���ļ�ĩβ
    fs.seekg(0, ios_base::end);
    streampos num = fs.tellg();
    cout << (int)num << endl;

    if ((int)num <= 0) {
        // �ļ�������
        cout << "������" << endl;

        // β��׷������
        staffList.push_back(new CStaff( 1001,"aaa","123456", ADMIN));
        staffList.push_back(new CStaff(1002,"bbb","123456", MANAGER));

        list<CStaff *>::iterator it; // ָ��ָ��Ԫ�صĵ�ַ
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
            cout << "������" << endl;
            // ���ж�ȡ -> �б�����
            while (fs.peek() != EOF) {
                fs.getline(buf, 255);
                cout << buf << endl;
                sscanf(buf,"%d %s %s %d", &id,name,pwd,&role);
                cout<<id<<"-"<<endl;
                staffList.push_back(new CStaff(id,name,pwd,role));
            }
        // ����������
        list<CStaff*>::iterator it; // ָ��ָ��Ԫ�صĵ�ַ
        for (it = staffList.begin(); it != staffList.end(); ++it) {
            fs << (*it)->getId() << "," << (*it)->getName() << "," << (*it)->getPwd() << "," << (*it)->getRole() << endl;
        }

// �ر��ļ�
        fs.close();
        }

    // �ر��ļ�
    fs.close();
}
