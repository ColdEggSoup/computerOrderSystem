#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <fstream>
#include "globalFile.h"

class orderFile
{
public:
	// ���캯��
	orderFile();
	// ����ԤԼ��¼
	void updateOrder();
	// ��¼��������key��value
	map<int, map<string, string>> m_orderData;
	//ԤԼ��¼����
	int m_size;
};

