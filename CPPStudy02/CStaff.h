//
// Created by 1 on 2024/5/18.
//

#ifndef C_STUDY_CSTAFF_H
#define C_STUDY_CSTAFF_H
#define ADMIN 1
#define MANAGER 2
#define WAITER 3

class CStaff {
    //默认私有
public:
    //一般由小到大定义，提高空间利用率
    //类定义只能定义成员，不能赋值初始化
    int id;
    char name[10];
    int role;
    char * getPwd();//这样可以使用私有的pwd
    void setPwd(char const*newpwd);//这样就能修改值
private:
    char pwd[10];

};


#endif //C_STUDY_CSTAFF_H
