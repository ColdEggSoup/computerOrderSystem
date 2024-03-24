#include "teacher.h"

teacher::teacher() {}
// �вι���
teacher::teacher(string Empid, string name, string password)  {
	this->m_EmpId = Empid;
	this->m_Name = name;
	this->m_Password = password;
}
// �˵�����
void teacher::operaMenu()  {
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|        1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
// �鿴����ԤԼ
void teacher::showAllOrder()  {
	orderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++) {
		cout << i + 1 << "��";//��ʾ���
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << " ";
		cout << "ʱ���" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "������" << of.m_orderData[i]["roomId"] << " ";
		string status = "״̬��";
		if (of.m_orderData[i]["status"] == "1") status += "�����";
		else if (of.m_orderData[i]["status"] == "2") status += "ԤԼ�ɹ�";
		else if (of.m_orderData[i]["status"] == "-1") status += "���δͨ��";
		else status += "ȡ��ԤԼ";
		cout << status << endl;

	}
	system("pause");
	system("cls");
}
// ���ԤԼ
void teacher::validOrder() {
	orderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector <int> v;
	int index = 1;
	for (int i = 0; i < of.m_size;i++) {
		if (of.m_orderData[i]["status"] == "1") {
			v.push_back(i);
			cout << index++ << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << " ";
			cout << "ʱ���" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "������" << of.m_orderData[i]["roomId"] << " ";
			string status = "״̬��";
			if (of.m_orderData[i]["status"] == "1") status += "�����";
			else if (of.m_orderData[i]["status"] == "2") status += "ԤԼ�ɹ�";
			else if (of.m_orderData[i]["status"] == "-1") status += "���δͨ��";
			else status += "ȡ��ԤԼ";
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0�����أ�" << endl;
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
				cout << "��������˽��" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ret;

				if (ret == 1) of.m_orderData[v[select - 1]]["status"] = "2";
				else if (ret == 2) of.m_orderData[v[select - 1]]["status"] = "-1";
				of.updateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}