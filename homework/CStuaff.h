#ifndef CSTUAFF_H
#define CSTUAFF_H

#include <string>
#include <vector>

#define ADMIN 1
#define MANAGER 2
#define WAITER 3

class CStaff {
public:
    int id;
    std::string name;
    std::string pwd;
    int role;

    // ���캯��
    CStaff(int id = 1001, const std::string& name = "admin", const std::string& pwd = "123456", int role = ADMIN);

    // ��ӡԱ����Ϣ
    static void printStaffInfo(const std::vector<CStaff>& staffArr);

    // ���Ա��
    static void addStaff(std::vector<CStaff>& staffArr, const CStaff& newStaff);
};

int staffJudge(char *name,CStaff *staffArr[],int staffCount);
#endif // CSTAFF_H
