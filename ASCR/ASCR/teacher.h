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
    // Ĭ�Ϲ���
    teacher();
    // �вι���
    teacher(string  Empid, string name, string password);
    // �˵�����
    virtual void operaMenu();
    // �鿴����ԤԼ
    void showAllOrder();
    // ���ԤԼ
    void validOrder();
    //��ְ��ѧ��
    string m_Name;
    string m_EmpId;
};

