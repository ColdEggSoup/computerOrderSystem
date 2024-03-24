#include "student.h"
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"
// 默认构造
student::student(){}
// 有参构造
student::student(string id, string name, string password) {
	//初始化属性
	this->m_Id = id;
	this->m_Name = name;
	this->m_Password = password;

	// 初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FiLE, ios::in);

	computerRoom com;
	while (ifs >> com.m_comId && ifs >> com.m_maxNum)
	{
		vCom.push_back(com);
	}
}
// 菜单界面
void student::operaMenu() {
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
// 申请预约
void student::applyOrder() {
	int date = 0;
	int interval = 0;
	int room = 0;
	cout << "选择申请日期：周一~周五，输入1~5选择日期：" << endl;
	while (1) {
		cin >> date;
		if (date >= 1 && date <= 5) break;
		cout << "输入有误，请重新输入！" << endl;
	}
	cout << "选择申请时段：上午/下午，输入1~2选择时段：" << endl;
	while (1) {
		cin >> interval;
		if (interval == 1 || interval == 2) break;
		cout << "输入有误，请重新输入！" << endl;
	}
	cout << "选择申请机房：" << endl;
	for (int i = 0; i < vCom.size();i++) cout << vCom[i].m_comId << "号机房容量为：" << vCom[i].m_maxNum << endl;

	while (1) {
		cin >> room;
		if (room >= 1 && room <= 3) break;
		cout << "输入有误，请重新输入！" << endl;
	}
	cout << "申请预约成功，审核中" << endl;

	ofstream ofs;
	ofs.open(ORDER_FiLE, ios::app);
	ofs << "date:" << date << " ";	
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";	
	ofs << "stuName:" << this->m_Name << " ";	
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
}
// 查看自身预约
void student::showMyOrder() {
	orderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_size;i++) {
		//若是int类型，需要将string转int：
		//1、利用.c_str()转为const char*，2、再利用atoi(const char*) 转int
		if (this->m_Id == of.m_orderData[i]["stuId"]) //找到对应自身学号的预约
		{
			cout << "预约日期：周" << of.m_orderData[i]["date"]<< " ";
			cout << "时间段" << (of.m_orderData[i]["interval"] == "1"?"上午":"下午") << " ";
			cout << "机房号" << of.m_orderData[i]["roomId"] << " ";
			string status = "状态：";
			if (of.m_orderData[i]["status"] == "1") status += "审核中";
			else if (of.m_orderData[i]["status"] == "2") status += "预约成功";
			else if (of.m_orderData[i]["status"] == "-1") status += "审核未通过";
			else status += "取消预约";
			cout << status <<endl;
		}
	}
	system("pause");
	system("cls");
}
// 查看所有预约
void student::showAllOrder() {
	orderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++) {
		cout << i + 1 << "、";//显示序号
		cout << "预约日期：周" << of.m_orderData[i]["date"] << " ";
		cout << "时间段" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "机房号" << of.m_orderData[i]["roomId"] << " ";
		string status = "状态：";
		if (of.m_orderData[i]["status"] == "1") status += "审核中";
		else if (of.m_orderData[i]["status"] == "2") status += "预约成功";
		else if (of.m_orderData[i]["status"] == "-1") status += "审核未通过";
		else status += "取消预约";
		cout << status << endl;
		
	}
	system("pause");
	system("cls");
}
// 取消预约
void student::cancelOrder() {
	orderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		if (this->m_Id == of.m_orderData[i]["stuId"]) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << of.m_orderData[i]["date"] << " ";
				cout << "时间段" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
				cout << "机房号" << of.m_orderData[i]["roomId"] << " ";
				string status = "状态：";
				if (of.m_orderData[i]["status"] == "1") status += "审核中";
				else if (of.m_orderData[i]["status"] == "2") status += "预约成功";
				else if (of.m_orderData[i]["status"] == "-1") status += "审核未通过";
				else status += "取消预约";
				cout << status << endl;
			}
		}
	}


	cout << "请输入取消的记录，0代表返回：" << endl;
	int select = 0;
	while (1) {
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "已取消预约" << endl;
				break;
				}
		}
		cout << "输入有误，请重新输入：" << endl;
	}
}
//学生学号
