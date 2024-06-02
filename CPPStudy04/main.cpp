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
    // 删除第一个元素
    std::cout << "删除后:" << std::endl;
    staffVec.erase(it);

    // 清空整个容器
    std::cout << "清空容器:" << std::endl;
    staffVec.clear();

    // 确认容器已清空
    std::cout << "容器大小: " << staffVec.size() << std::endl;
}

void demo_list() {
    // 1. 创建

    list < Staff * > staffList;

    // 2. 尾部追加
    staffList.push_back(new Staff(1001, "admin", "123456", ADMIN));
    staffList.push_back(new Staff(1002, "manager", "123456", MANAGER));

    // 3. 访问 -- 迭代器访问法
    list<Staff*>::iterator it; // 指针，指向元素的地址
    for (it = staffList.begin(); it != staffList.end(); it++) {
        cout << (*it)->getId() << " " << (*it)->getName() << endl;
    }

    // 访问元素
    if (!staffList.empty()) {
        Staff* first = staffList.front();
        cout << first->getId() << " " << first->getName() << endl;
        Staff* backone = staffList.back();
        cout << backone->getId() << " " << backone->getName() << endl;

    }

    // 清空列表前释放内存
    for (Staff* staff : staffList) {
        delete staff;
    }
    staffList.clear();

    // 检查列表是否清空
    if (staffList.empty()) {
        cout << "staffList all clear, size: " << staffList.size() << endl;
    }
}

int main(){
    demo_vector();
    return 0;
}

