//
// Created by 1 on 2024/5/18.
//

#ifndef C_STUDY_CSTAFF_H
#define C_STUDY_CSTAFF_H
#define ADMIN 1
#define MANAGER 2
#define WAITER 3

class CStaff {
    //Ĭ��˽��
public:

//    CStaff(int id,char *name,char *pwd,int role);

    //һ����С�����壬��߿ռ�������
    //�ඨ��ֻ�ܶ����Ա�����ܸ�ֵ��ʼ��
    int id;
    char name[10];
    int role;
    //Ĭ�Ϲ��캯��Ҫô���������Ҫô��������
    CStaff(int id = 1001,char *name = "admin",char *pwd = "123456",int role = ADMIN);
    ~CStaff();
    char * getPwd();//��������ʹ��˽�е�pwd
    void setPwd(char const*newpwd);//���������޸�ֵ
    void printf();
private:
    char pwd[10];

};


#endif //C_STUDY_CSTAFF_H
