#include <iostream>
using namespace std;
#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
void studentMenu(Identity*& stu);
void managerMenu(Identity*& man);
void teacherMenu(Identity*& tea);
//登录功能 参数1 操作文件名 参数2 操作身份类型
void LoginIn(string fileName, int type) {
    
    //父类指针，用于指向子类对象
    Identity* person = NULL;

    //读文件
    ifstream ifs;
    ifs.open(fileName, ios::in);

    //判断文件是否存在
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;

    }
    //准备接收用户的信息
    string id;
    string name;
    string password;

    //判断身份
    if (type == 1) // 学生身份
    { 
        cout << "请输入你的学号：" << endl;
        cin >> id;
    }
    else if (type == 2) //教师身份
    {
        cout << "请输入你的职工号：" << endl;
        cin >> id;
    }

    cout << "请输入用户名：" << endl;
    cin >> name;

    cout << "请输入密码" << endl;
    cin >> password;

    if (type == 1) {
        //学生身份认证
        string fId;
        string fName;
        string fPassword;
        while (ifs >> fId && ifs >> fName && ifs >> fPassword) {
            if (fId == id && fName == name && fPassword == password)
            {
                cout << "学生验证登录成功！" << endl;
                system("pause");
                system("cls");
                person = new student(id, name, password);
                //进入学生身份的主菜单
                studentMenu(person);
                return;

            }
        }
    }
    else if (type == 2) {
        //教师身份认证
        string fId;
        string fName;
        string fPassword;
        while (ifs >> fId && ifs >> fName && ifs >> fPassword) {
            if (fId == id && fName == name && fPassword == password)
            {
                cout << "教师验证登录成功！" << endl;
                system("pause");
                system("cls");
                person = new teacher(id, name, password);
                //进入教师身份的主菜单
                teacherMenu(person);
                return;
            }
        }
    }
    else if (type == 3) {        
        //管理员身份认证
        string fName;
        string fPassword;
        while (ifs >> fName && ifs >> fPassword) {
            if (fName == name && fPassword == password)
            {
                cout << "管理员验证登录成功！" << endl;
                system("pause");
                system("cls");
                person = new manager(name, password);
                //进入管理员身份的主菜单
                managerMenu(person);
                return;
            }
        }
    }

}
// 进入学生子菜单界面
void studentMenu(Identity*& stu) {
    while (1)
    {
        stu->operaMenu();
        student* stu1 = (student*)stu;

        int select = 0;
        cin >> select;

        if (select == 1) {
            stu1->applyOrder();//申请预约
        }
        else if (select == 2) {
            stu1->showMyOrder();//查看自身预约
        }
        else if (select == 3) {
            stu1->showAllOrder();//查看所有预约
        }
        else if (select == 4) {
            stu1->cancelOrder(); //取消预约
        }
        else {
            //注销模块
            delete stu;
            cout << "注销成功！" << endl;
            system("pause");
            system("cls");
            return;
        }

    }
}
// 进入管理员子菜单界面
void managerMenu(Identity*& man) {
    while (1) {
        man->operaMenu();

        manager* man1 = (manager*)man;
        int select = 0;

        cin >> select;
        
        if (select == 1) //添加账号
        {
            cout << "添加账号" << endl;
            man1->createAccount();
        }
        else if (select == 2 )// 查看账号
        { 
            cout << "查看账号" << endl;
            man1->showAccount();
        }
        else if (select == 3) // 查看机房
        { 
            cout << "查看机房" << endl;
            man1->showInfo();
        }
        else if (select == 4) // 清空预约
        { 
            cout << "清空预约" << endl;
            man1->cleanFile();
        }
        else {
            //注销模块
            delete man;//销毁堆区对象
            cout << "注销成功！" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void teacherMenu(Identity*& tea) {
    while (1)
    {
        //进入教师子菜单
        tea->operaMenu();

        teacher* tea1 = (teacher*)tea;
        int select = 0;

        cin >> select;

        if (select == 1) //添加账号
        {
            cout << "查看所有预约：" << endl;
            tea1->showAllOrder();
        }
        else if (select == 2)// 查看账号
        {
            cout << "审核预约" << endl;
            tea1->validOrder();
        }
        else {
            //注销模块
            delete tea;//销毁堆区对象
            cout << "注销成功！" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}
int main() {
    //编写主界面
    int select = 0; 

    while (1)
    {
        cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";

        cin >> select; // 接受用户选择

        switch (select)
        {
        case 1: // 学生身份
            LoginIn(STUDENT_FiLE, 1);
            break;
        case 2: // 老师身份
            LoginIn(TEACHER_FiLE, 2);
            break;
        case 3: //管理员身份
            LoginIn(ADMIN_FiLE, 3);
            break;
        case 0: // 退出
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;   
            break;
        default:
            cout << "输出有误，请重新输入！" << endl;
            system("pause");
            system("cls");
            break;
        }
    }



    system("pause");

    return 0;
}