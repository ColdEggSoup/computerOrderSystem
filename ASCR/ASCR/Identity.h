#pragma once // ��ֹͷ�ļ��ظ�����
#include <iostream>

using namespace std;

class Identity {
public:
	//�����˵� ���麯��
	virtual void operaMenu() = 0;
	//�û���
	string m_Name;
	//����
	string m_Password;
};