#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "computerRoom.h"
using namespace std;

#include "Identity.h"
class student :
    public Identity
{
public:
    // 默认构造
    student();
    // 有参构造
    student(string id, string name, string password);
    // 菜单界面
    virtual void operaMenu();
    // 申请预约
    void applyOrder();
    // 查看自身预约
    void showMyOrder();
    // 查看所有预约
    void showAllOrder();
    // 取消预约
    void cancelOrder();
    //学生学号
    string m_Name;
    string m_Id;

    // 机房容器
    vector <computerRoom> vCom;

};

