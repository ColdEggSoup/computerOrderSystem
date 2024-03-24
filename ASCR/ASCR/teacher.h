#pragma once

#include <iostream>
using namespace std;
#include <string>
#include "orderFile.h"
#include <vector>
#include "Identity.h"
class teacher :
    public Identity
{
public:
    // 默认构造
    teacher();
    // 有参构造
    teacher(string  Empid, string name, string password);
    // 菜单界面
    virtual void operaMenu();
    // 查看所有预约
    void showAllOrder();
    // 审核预约
    void validOrder();
    //教职工学号
    string m_Name;
    string m_EmpId;
};

