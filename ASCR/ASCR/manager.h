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
    // Ĭ�Ϲ���
    manager();
    // �вι���
    manager(string name, string password);
    // �˵�����
    virtual void operaMenu();
    // ����˺�
    void createAccount();
    // �鿴�˺�
    void showAccount();
    // �鿴������Ϣ
    void showInfo();
    // ���ԤԼ��¼
    void cleanFile();
    // ��ʼ������
    void initvector();
    void initcomputer();
    //����ظ�
    bool checkRepeat(string id, int type);
    // ѧ������
    vector<student> vStu;
    // ��ʦ����
    vector <teacher> vTea;
    // ��������
    vector <computerRoom> vCom;

};

