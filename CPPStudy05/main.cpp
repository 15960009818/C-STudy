#include "CData.h"

int main() {
    CData::staffInit();
    
    // �������
    list<CStaff*>::iterator it; // ָ��ָ��Ԫ�صĵ�ַ
    for (it = CData::staffList.begin(); it != CData::staffList.end(); ++it) {
        cout << (*it)->getId() << " " << (*it)->getName() << " " << (*it)->getPwd() << " " << (*it)->getRole() << endl;
    }
    
    return 0;
}
