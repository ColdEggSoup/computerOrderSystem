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
    // Ĭ�Ϲ���
    student();
    // �вι���
    student(string id, string name, string password);
    // �˵�����
    virtual void operaMenu();
    // ����ԤԼ
    void applyOrder();
    // �鿴����ԤԼ
    void showMyOrder();
    // �鿴����ԤԼ
    void showAllOrder();
    // ȡ��ԤԼ
    void cancelOrder();
    //ѧ��ѧ��
    string m_Name;
    string m_Id;

    // ��������
    vector <computerRoom> vCom;

};

