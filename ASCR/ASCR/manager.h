#pragma once
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include <fstream>
#include <vector>
#include "computerRoom.h"

class manager :
    public Identity
{
public:
    // 默认构造
    manager();
    // 有参构造
    manager(string name, string password);
    // 菜单界面
    virtual void operaMenu();
    // 添加账号
    void createAccount();
    // 查看账号
    void showAccount();
    // 查看机房信息
    void showInfo();
    // 清空预约记录
    void cleanFile();
    // 初始化容器
    void initvector();
    void initcomputer();
    //检测重复
    bool checkRepeat(string id, int type);
    // 学生容器
    vector<student> vStu;
    // 教师容器
    vector <teacher> vTea;
    // 机房容器
    vector <computerRoom> vCom;

};

