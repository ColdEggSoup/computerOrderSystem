#include "teacher.h"

teacher::teacher() {}
// 有参构造
teacher::teacher(string Empid, string name, string password)  {
	this->m_EmpId = Empid;
	this->m_Name = name;
	this->m_Password = password;
}
// 菜单界面
void teacher::operaMenu()  {
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|        1.查看所有预约          |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.审核预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
// 查看所有预约
void teacher::showAllOrder()  {
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
// 审核预约
void teacher::validOrder() {
	orderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;

	vector <int> v;
	int index = 1;
	for (int i = 0; i < of.m_size;i++) {
		if (of.m_orderData[i]["status"] == "1") {
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
	cout << "请输入审核的预约记录，0代表返回：" << endl;
	int select = 0;
	int ret = 0;

	while (1)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0) break;

			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;

				if (ret == 1) of.m_orderData[v[select - 1]]["status"] = "2";
				else if (ret == 2) of.m_orderData[v[select - 1]]["status"] = "-1";
				of.updateOrder();
				cout << "审核完毕！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}