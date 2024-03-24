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
//��¼���� ����1 �����ļ��� ����2 �����������
void LoginIn(string fileName, int type) {
    
    //����ָ�룬����ָ���������
    Identity* person = NULL;

    //���ļ�
    ifstream ifs;
    ifs.open(fileName, ios::in);

    //�ж��ļ��Ƿ����
    if (!ifs.is_open()) {
        cout << "�ļ�������" << endl;
        ifs.close();
        return;

    }
    //׼�������û�����Ϣ
    string id;
    string name;
    string password;

    //�ж����
    if (type == 1) // ѧ�����
    { 
        cout << "���������ѧ�ţ�" << endl;
        cin >> id;
    }
    else if (type == 2) //��ʦ���
    {
        cout << "���������ְ���ţ�" << endl;
        cin >> id;
    }

    cout << "�������û�����" << endl;
    cin >> name;

    cout << "����������" << endl;
    cin >> password;

    if (type == 1) {
        //ѧ�������֤
        string fId;
        string fName;
        string fPassword;
        while (ifs >> fId && ifs >> fName && ifs >> fPassword) {
            if (fId == id && fName == name && fPassword == password)
            {
                cout << "ѧ����֤��¼�ɹ���" << endl;
                system("pause");
                system("cls");
                person = new student(id, name, password);
                //����ѧ����ݵ����˵�
                studentMenu(person);
                return;

            }
        }
    }
    else if (type == 2) {
        //��ʦ�����֤
        string fId;
        string fName;
        string fPassword;
        while (ifs >> fId && ifs >> fName && ifs >> fPassword) {
            if (fId == id && fName == name && fPassword == password)
            {
                cout << "��ʦ��֤��¼�ɹ���" << endl;
                system("pause");
                system("cls");
                person = new teacher(id, name, password);
                //�����ʦ��ݵ����˵�
                teacherMenu(person);
                return;
            }
        }
    }
    else if (type == 3) {        
        //����Ա�����֤
        string fName;
        string fPassword;
        while (ifs >> fName && ifs >> fPassword) {
            if (fName == name && fPassword == password)
            {
                cout << "����Ա��֤��¼�ɹ���" << endl;
                system("pause");
                system("cls");
                person = new manager(name, password);
                //�������Ա��ݵ����˵�
                managerMenu(person);
                return;
            }
        }
    }

}
// ����ѧ���Ӳ˵�����
void studentMenu(Identity*& stu) {
    while (1)
    {
        stu->operaMenu();
        student* stu1 = (student*)stu;

        int select = 0;
        cin >> select;

        if (select == 1) {
            stu1->applyOrder();//����ԤԼ
        }
        else if (select == 2) {
            stu1->showMyOrder();//�鿴����ԤԼ
        }
        else if (select == 3) {
            stu1->showAllOrder();//�鿴����ԤԼ
        }
        else if (select == 4) {
            stu1->cancelOrder(); //ȡ��ԤԼ
        }
        else {
            //ע��ģ��
            delete stu;
            cout << "ע���ɹ���" << endl;
            system("pause");
            system("cls");
            return;
        }

    }
}
// �������Ա�Ӳ˵�����
void managerMenu(Identity*& man) {
    while (1) {
        man->operaMenu();

        manager* man1 = (manager*)man;
        int select = 0;

        cin >> select;
        
        if (select == 1) //����˺�
        {
            cout << "����˺�" << endl;
            man1->createAccount();
        }
        else if (select == 2 )// �鿴�˺�
        { 
            cout << "�鿴�˺�" << endl;
            man1->showAccount();
        }
        else if (select == 3) // �鿴����
        { 
            cout << "�鿴����" << endl;
            man1->showInfo();
        }
        else if (select == 4) // ���ԤԼ
        { 
            cout << "���ԤԼ" << endl;
            man1->cleanFile();
        }
        else {
            //ע��ģ��
            delete man;//���ٶ�������
            cout << "ע���ɹ���" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void teacherMenu(Identity*& tea) {
    while (1)
    {
        //�����ʦ�Ӳ˵�
        tea->operaMenu();

        teacher* tea1 = (teacher*)tea;
        int select = 0;

        cin >> select;

        if (select == 1) //����˺�
        {
            cout << "�鿴����ԤԼ��" << endl;
            tea1->showAllOrder();
        }
        else if (select == 2)// �鿴�˺�
        {
            cout << "���ԤԼ" << endl;
            tea1->validOrder();
        }
        else {
            //ע��ģ��
            delete tea;//���ٶ�������
            cout << "ע���ɹ���" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}
int main() {
    //��д������
    int select = 0; 

    while (1)
    {
        cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
        cout << endl << "�������������" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.ѧ������           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.��    ʦ           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.�� �� Ա           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.��    ��           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "��������ѡ��: ";

        cin >> select; // �����û�ѡ��

        switch (select)
        {
        case 1: // ѧ�����
            LoginIn(STUDENT_FiLE, 1);
            break;
        case 2: // ��ʦ���
            LoginIn(TEACHER_FiLE, 2);
            break;
        case 3: //����Ա���
            LoginIn(ADMIN_FiLE, 3);
            break;
        case 0: // �˳�
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");
            return 0;   
            break;
        default:
            cout << "����������������룡" << endl;
            system("pause");
            system("cls");
            break;
        }
    }



    system("pause");

    return 0;
}