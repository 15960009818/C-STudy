#include"CData.h"
#include <iostream>
#include <fstream>
#include <string>
#include "CStaff.h"
#include "list"
using namespace std;

// ���徲̬��Ա����
list<CStaff*> CData::staffList;

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
        staffList.push_back(new CStaff(1001, "admin", "123456", ADMIN));
        staffList.push_back(new CStaff(1002, "manager", "123456", MANAGER));

        // ͬ�����ݵ��ļ�
        syncStaffData();
    } else {
        char buf[256] = {0};
        cout << "������" << endl;
        // ���ж�ȡ -> �б�����
        while (fs.peek() != EOF) {
            fs.getline(buf, 255);
            cout << buf << endl;
        }
    }

    // �ر��ļ�
    fs.close();
}

void CData::syncStaffData() {
    // �����ļ�����
    fstream fs;

    // ��д��ʽ���ļ���������������
    fs.open("data/staff.txt", ios_base::out | ios_base::trunc);

    if (!fs.is_open()) {
        cerr << "�޷����ļ�����д��" << endl;
        return;
    }

    // ����д��staffList�е�����
    list<CStaff*>::iterator it; // ָ��ָ��Ԫ�صĵ�ַ
    for (it = staffList.begin(); it != staffList.end(); ++it) {
        fs << (*it)->getId() << "," << (*it)->getName() << "," << (*it)->getPwd() << "," << (*it)->getRole() << endl;
    }

    // �ر��ļ�
    fs.close();
}