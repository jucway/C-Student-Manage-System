#include<iostream>
#include<fstream>
#include"student.h"
using namespace std;
void menu()
{
	cout << "\n\n\t\t----------------ѧ����Ϣ����ϵͳ------------------" << endl << endl;
	cout << "\t\t1����ӹ���" << " " << "\t2��ɾ������" << endl << endl;
	cout << "\t\t3�����ҹ���" << " " << "\t4����ʾ����" << endl << endl;
	cout << "\t\t5���ɼ�����" << " " << "\t6���˳�" << endl << endl;
	return;
}
//��ӹ��ܽ���
void menu1()
{
	cout << "\n\n\t\t��ӹ���" << endl << endl;
	cout << "\t\t1������ѧ����Ϣ" << endl << endl;
	cout << "\t\t2������" << endl << endl;
	return;
}

//ɾ�����ܽ���
void menu2()
{
	cout << "\n\n\t\tɾ������" << endl << endl;
	cout << "\t\t1����ѧ��ɾ��ѧ����Ϣ" << endl << endl;
	cout << "\t\t2������" << endl << endl;
	return;
}
//��ѯ���ܽ���
void menu3()
{
	cout << "\n\n\t\t��Ϣ��ѯ����" << endl << endl;
	cout << "\t\t1����������ѯ" << endl << endl;
	cout << "\t\t2����ѧ�Ų�ѯ" << endl << endl;
	cout << "\t\t3������" << endl << endl;
	return;
}

//��ʾ���ܽ���
void menu4()
{
	cout << "\n\n\t\t��ʾ����" << endl << endl;
	cout << "\t\t1����ʾ����ѧ����Ϣ" << endl << endl;
	cout << "\t\t2��ͳ��������" << endl << endl;
	cout << "\t\t3������" << endl << endl;
	return;
}


//�ɼ����ܽ���
void menu5()
{
	cout << "\n\n\t\t�ɼ�����" << endl << endl;
	cout << "\t\t1��ͳ�Ƽ�����" << endl << endl;
	cout << "\t\t2��������������" << endl << endl;
	cout << "\t\t3������" << endl << endl;
	return;
}


void window()
{
	int choice, choice1, choice2, choice3, choice4, choice5;
	function sims;
	while (1)
	{
		menu();
		cout << "��ѡ����Ҫ���еĲ�����";
		cin >> choice;
		while (choice != 6)
		{
			while (choice <= 0 || choice > 6)
			{
				cout << "�����������������룡";
				cin >> choice;
			}
			switch (choice)
			{
			case 1:
				while (1)
				{
					menu1();
					cout << "������Ҫ���еĲ�����";
					cin >> choice1;
					if (choice1 == 1)
					{
						sims.add();
						cout << "\n\n\n\t\tѧ���ɼ���Ϣ�����£�" << endl;
					}
					if (choice1 == 2)
					{
						// ����
						system("cls");
						window();
					}
					break;
				}break;
			case 2:
				while (1)
				{
					menu2();
					cout << "������Ҫ���еĲ�����";
					cin >> choice2;
					if (choice2 == 1)
					{
						sims.Del();
						cout << "\n\n\n\t\tѧ���ɼ���Ϣ�����£�" << endl;
					}
					if (choice2 == 2)
					{
						system("cls");
						window();
					}
					break;
				}break;
			case 3:
				while (1)
				{
					menu3();
					cout << "������Ҫ���еĲ�����";
					cin >> choice3;
					if (choice3 == 1)
					{
						sims.search_byname();
					}
					else
						if (choice3 == 2)
							sims.search_byid();
						else if (choice3 == 3)
						{
							system("cls");
							window();
						}
					if (choice3 != 1 && choice3 != 2)
						break;
				}break;
			case 4:
				while (1)
				{
					menu4();
					cout << "������Ҫ���еĲ�����";
					cin >> choice4;
					if (choice4 == 1)
					{
						sims.show();
					}
					if (choice4 == 2)
					{
						// ͳ������
						cout << endl;
						cout << "\t\t=======��ʾѧ��������=======" << endl;
						sims.showCount();
					}
					if (choice4 == 3)
					{
						system("cls");
						window();
					}
					break;
				}break;
			case 5:
				while (1)
				{
					menu5();
					cout << "������Ҫ���еĲ�����";
					cin >> choice5;
					if (choice5 == 1)
					{
						double  jiege;
						jiege = sims.getpassrate();
						cout << endl;
						cout << "\t\t=======������=======" << endl;
						cout << "\t\t ������Ϊ��" << jiege*100 <<"%"<< endl;
					}
					if (choice5 == 2)
						sims.showinfo();
					if (choice5 == 3)
					{
						system("cls");
						window();
					}
					if (choice5 != 1 && choice5 != 2)
						break;
				}break;
			case 6:
				break;
			}
		}
	}

}