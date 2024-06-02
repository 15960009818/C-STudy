#include "CData.h"

int main() {
    CData::staffInit();
    
    // 测试输出
    list<CStaff*>::iterator it; // 指针指向元素的地址
    for (it = CData::staffList.begin(); it != CData::staffList.end(); ++it) {
        cout << (*it)->getId() << " " << (*it)->getName() << " " << (*it)->getPwd() << " " << (*it)->getRole() << endl;
    }
    
    return 0;
}
