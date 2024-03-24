#include "manager.h"
#include <algorithm>
#include "globalFile.h"

// 默认构造
manager::manager() {}
// 有参构造
manager::manager(string name, string password) {
	this->m_Name = name;
	this->m_Password = password;
	
	//初始化容器，获取到所有文件中学生和老师的信息
	this->initvector();
	this->initcomputer();
}
// 菜单界面
void manager::operaMenu() {
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
// 添加账号
void manager::createAccount() {
	cout << "请输入添加账号的类型：" << endl;
	cout << "1. 添加学生" << endl;
	cout << "2. 添加老师" << endl;

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
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入：";
	}
	else if (select == 2) {
		fileName = TEACHER_FiLE;
		tip = "请输入职工号";
		errorTip = "职工号重复，请重新输入：";
	}
	else
	{
		cout << "输入有误，返回初始界面！" << endl;
		return;
	}
	ofs.open(fileName, ios::out | ios::app);//利用追加方式写文件

	string id, name, password;
	cout << tip << endl;
	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, select);

		if (ret) cout << errorTip << endl;// 有重复
		else break;
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> password;

	ofs << id << " " << name << " " << password << " " << endl;
	cout << "添加成功！" << endl;

	ofs.close();
	//初始化容器
	this->initvector();

}
// 查看账号
void showStudent(student& s) {
	cout << "学生学号："<< s.m_Id << "学生姓名："<< s.m_Name << " 学生密码：" << s.m_Password << endl;
}
void showTeacher(teacher& t) {
	cout << "教职工学号：" << t.m_EmpId << "教职工姓名：" << t.m_Name << "教职工密码：" << t.m_Password << endl;
}
void showComputer(computerRoom& c) {
	cout << "机房编号：" << c.m_comId << "机房最大容量：" << c.m_maxNum << endl;
}
void manager::showAccount() {
	cout << "请选择查看内容：" << endl;
	cout << "1. 查看所有学生" << endl;
	cout << "2. 查看所有老师" << endl;
	int select = 0;
	cin >> select;

	if (select == 1) {
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(),showStudent);//for_each 是STL里的，还不会
	}
	else if (select == 2) {
		cout << "所有教职工信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), showTeacher);
	}
	system("pause");
	system("cls");
}
// 查看机房信息
void manager::showInfo() {
	cout << "机房信息如下：" << endl;
	for_each(vCom.begin(), vCom.end(), showComputer);
	system("pause");
	system("cls");
}
// 清空预约记录
void manager::cleanFile(){
	ofstream ofs(ORDER_FiLE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");

}
void manager::initvector() {

	//读取信息 学生、老师

	vStu.clear();
	vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FiLE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败！" << endl;
		return;
	}
	student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Password) {
		vStu.push_back(s);
	}
	cout << "当前学生数量为： " << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FiLE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败！" << endl;
		return;
	}
	teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Password) {
		vTea.push_back(t);
	}
	cout << "当前老师数量为： " << vTea.size() << endl;
	ifs.close();

}
void manager::initcomputer() {
	ifstream ifs;
	ifs.open(COMPUTER_FiLE, ios::in);

	computerRoom c;
	while (ifs >> c.m_comId && ifs >> c.m_maxNum) {
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;
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
