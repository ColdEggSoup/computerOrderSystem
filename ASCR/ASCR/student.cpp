#include "student.h"
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"
// Ĭ�Ϲ���
student::student(){}
// �вι���
student::student(string id, string name, string password) {
	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Password = password;

	// ��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FiLE, ios::in);

	computerRoom com;
	while (ifs >> com.m_comId && ifs >> com.m_maxNum)
	{
		vCom.push_back(com);
	}
}
// �˵�����
void student::operaMenu() {
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
// ����ԤԼ
void student::applyOrder() {
	int date = 0;
	int interval = 0;
	int room = 0;
	cout << "ѡ���������ڣ���һ~���壬����1~5ѡ�����ڣ�" << endl;
	while (1) {
		cin >> date;
		if (date >= 1 && date <= 5) break;
		cout << "�����������������룡" << endl;
	}
	cout << "ѡ������ʱ�Σ�����/���磬����1~2ѡ��ʱ�Σ�" << endl;
	while (1) {
		cin >> interval;
		if (interval == 1 || interval == 2) break;
		cout << "�����������������룡" << endl;
	}
	cout << "ѡ�����������" << endl;
	for (int i = 0; i < vCom.size();i++) cout << vCom[i].m_comId << "�Ż�������Ϊ��" << vCom[i].m_maxNum << endl;

	while (1) {
		cin >> room;
		if (room >= 1 && room <= 3) break;
		cout << "�����������������룡" << endl;
	}
	cout << "����ԤԼ�ɹ��������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FiLE, ios::app);
	ofs << "date:" << date << " ";	
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";	
	ofs << "stuName:" << this->m_Name << " ";	
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
}
// �鿴����ԤԼ
void student::showMyOrder() {
	orderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_size;i++) {
		//����int���ͣ���Ҫ��stringתint��
		//1������.c_str()תΪconst char*��2��������atoi(const char*) תint
		if (this->m_Id == of.m_orderData[i]["stuId"]) //�ҵ���Ӧ����ѧ�ŵ�ԤԼ
		{
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"]<< " ";
			cout << "ʱ���" << (of.m_orderData[i]["interval"] == "1"?"����":"����") << " ";
			cout << "������" << of.m_orderData[i]["roomId"] << " ";
			string status = "״̬��";
			if (of.m_orderData[i]["status"] == "1") status += "�����";
			else if (of.m_orderData[i]["status"] == "2") status += "ԤԼ�ɹ�";
			else if (of.m_orderData[i]["status"] == "-1") status += "���δͨ��";
			else status += "ȡ��ԤԼ";
			cout << status <<endl;
		}
	}
	system("pause");
	system("cls");
}
// �鿴����ԤԼ
void student::showAllOrder() {
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
// ȡ��ԤԼ
void student::cancelOrder() {
	orderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		if (this->m_Id == of.m_orderData[i]["stuId"]) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
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
	}


	cout << "������ȡ���ļ�¼��0�����أ�" << endl;
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
				cout << "��ȡ��ԤԼ" << endl;
				break;
				}
		}
		cout << "�����������������룺" << endl;
	}
}
//ѧ��ѧ��
