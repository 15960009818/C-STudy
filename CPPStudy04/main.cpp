//
// Created by 1 on 2024/6/1.
//

#include "main.h"
#include "iostream"
using namespace std;
#include <vector>
#include <list>
#include "CStuaff.h"
void demo_vector(){
    vector<Staff*> staffVec;

    staffVec.push_back(new Staff(1001,"admin","123456",ADMIN));
    staffVec.push_back(new Staff(1002,"admin1","123456",ADMIN));
    vector<Staff*>::iterator it=staffVec.begin();
    for(int i=0;i<staffVec.size();i++){
        cout<<staffVec[i]->getId()<<" "<<staffVec[i]->getName()<<endl;
    }
    for(int j=0;j<staffVec.size();j++){
        cout<<staffVec.at(j)->getId()<<" "<<endl;
    }

   for(it = staffVec.begin();it<staffVec.end();it++){
       cout<<(*it)->getId()<<" "<<(*it)->getName()<<endl;

   }
    // ɾ����һ��Ԫ��
    std::cout << "ɾ����:" << std::endl;
    staffVec.erase(it);

    // �����������
    std::cout << "�������:" << std::endl;
    staffVec.clear();

    // ȷ�����������
    std::cout << "������С: " << staffVec.size() << std::endl;
}

void demo_list() {
    // 1. ����

    list < Staff * > staffList;

    // 2. β��׷��
    staffList.push_back(new Staff(1001, "admin", "123456", ADMIN));
    staffList.push_back(new Staff(1002, "manager", "123456", MANAGER));

    // 3. ���� -- ���������ʷ�
    list<Staff*>::iterator it; // ָ�룬ָ��Ԫ�صĵ�ַ
    for (it = staffList.begin(); it != staffList.end(); it++) {
        cout << (*it)->getId() << " " << (*it)->getName() << endl;
    }

    // ����Ԫ��
    if (!staffList.empty()) {
        Staff* first = staffList.front();
        cout << first->getId() << " " << first->getName() << endl;
        Staff* backone = staffList.back();
        cout << backone->getId() << " " << backone->getName() << endl;

    }

    // ����б�ǰ�ͷ��ڴ�
    for (Staff* staff : staffList) {
        delete staff;
    }
    staffList.clear();

    // ����б��Ƿ����
    if (staffList.empty()) {
        cout << "staffList all clear, size: " << staffList.size() << endl;
    }
}

int main(){
    demo_vector();
    return 0;
}

