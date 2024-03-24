#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <fstream>
#include "globalFile.h"

class orderFile
{
public:
	// 构造函数
	orderFile();
	// 更新预约记录
	void updateOrder();
	// 记录的容器，key，value
	map<int, map<string, string>> m_orderData;
	//预约记录条数
	int m_size;
};

