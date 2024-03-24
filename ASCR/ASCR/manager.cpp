#include "manager.h"
#include <algorithm>
#include "globalFile.h"

// Ĭ�Ϲ���
manager::manager() {}
// �вι���
manager::manager(string name, string password) {
	this->m_Name = name;
	this->m_Password = password;
	
	//��ʼ����������ȡ�������ļ���ѧ������ʦ����Ϣ
	this->initvector();
	this->initcomputer();
}
// �˵�����
void manager::operaMenu() {
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
// ����˺�
void manager::createAccount() {
	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "1. ���ѧ��" << endl;
	cout << "2. �����ʦ" << endl;

	string fileName;
	string tip;
	string errorTip;
	int status = 0;
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FiLE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룺";
	}
	else if (select == 2) {
		fileName = TEACHER_FiLE;
		tip = "������ְ����";
		errorTip = "ְ�����ظ������������룺";
	}
	else
	{
		cout << "�������󣬷��س�ʼ���棡" << endl;
		return;
	}
	ofs.open(fileName, ios::out | ios::app);//����׷�ӷ�ʽд�ļ�

	string id, name, password;
	cout << tip << endl;
	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, select);

		if (ret) cout << errorTip << endl;// ���ظ�
		else break;
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> password;

	ofs << id << " " << name << " " << password << " " << endl;
	cout << "��ӳɹ���" << endl;

	ofs.close();
	//��ʼ������
	this->initvector();

}
// �鿴�˺�
void showStudent(student& s) {
	cout << "ѧ��ѧ�ţ�"<< s.m_Id << "ѧ��������"<< s.m_Name << " ѧ�����룺" << s.m_Password << endl;
}
void showTeacher(teacher& t) {
	cout << "��ְ��ѧ�ţ�" << t.m_EmpId << "��ְ��������" << t.m_Name << "��ְ�����룺" << t.m_Password << endl;
}
void showComputer(computerRoom& c) {
	cout << "������ţ�" << c.m_comId << "�������������" << c.m_maxNum << endl;
}
void manager::showAccount() {
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1. �鿴����ѧ��" << endl;
	cout << "2. �鿴������ʦ" << endl;
	int select = 0;
	cin >> select;

	if (select == 1) {
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(),showStudent);//for_each ��STL��ģ�������
	}
	else if (select == 2) {
		cout << "���н�ְ����Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), showTeacher);
	}
	system("pause");
	system("cls");
}
// �鿴������Ϣ
void manager::showInfo() {
	cout << "������Ϣ���£�" << endl;
	for_each(vCom.begin(), vCom.end(), showComputer);
	system("pause");
	system("cls");
}
// ���ԤԼ��¼
void manager::cleanFile(){
	ofstream ofs(ORDER_FiLE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");

}
void manager::initvector() {

	//��ȡ��Ϣ ѧ������ʦ

	vStu.clear();
	vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FiLE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Password) {
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ�� " << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FiLE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Password) {
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ�� " << vTea.size() << endl;
	ifs.close();

}
void manager::initcomputer() {
	ifstream ifs;
	ifs.open(COMPUTER_FiLE, ios::in);

	computerRoom c;
	while (ifs >> c.m_comId && ifs >> c.m_maxNum) {
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;
}
bool manager::checkRepeat(string id, int type) {
	if (type == 1) {
		for (vector <student>::iterator it = vStu.begin();it != vStu.end();it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else if (type == 2){
		for (vector <teacher>::iterator it = vTea.begin();it != vTea.end();it++) {
			if (id == it->m_EmpId) {
				return true;
			}
		}
	}
	return false;
}
