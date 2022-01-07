#include<iostream>
#include<fstream>
#include"student.h"
using namespace std;
void menu()
{
	cout << "\n\n\t\t----------------学生信息管理系统------------------" << endl << endl;
	cout << "\t\t1、添加功能" << " " << "\t2、删除功能" << endl << endl;
	cout << "\t\t3、查找功能" << " " << "\t4、显示功能" << endl << endl;
	cout << "\t\t5、成绩功能" << " " << "\t6、退出" << endl << endl;
	return;
}
//添加功能界面
void menu1()
{
	cout << "\n\n\t\t添加功能" << endl << endl;
	cout << "\t\t1、增加学生信息" << endl << endl;
	cout << "\t\t2、返回" << endl << endl;
	return;
}

//删除功能界面
void menu2()
{
	cout << "\n\n\t\t删除功能" << endl << endl;
	cout << "\t\t1、按学号删除学生信息" << endl << endl;
	cout << "\t\t2、返回" << endl << endl;
	return;
}
//查询功能界面
void menu3()
{
	cout << "\n\n\t\t信息查询功能" << endl << endl;
	cout << "\t\t1、按姓名查询" << endl << endl;
	cout << "\t\t2、按学号查询" << endl << endl;
	cout << "\t\t3、返回" << endl << endl;
	return;
}

//显示功能界面
void menu4()
{
	cout << "\n\n\t\t显示功能" << endl << endl;
	cout << "\t\t1、显示所有学生信息" << endl << endl;
	cout << "\t\t2、统计总人数" << endl << endl;
	cout << "\t\t3、返回" << endl << endl;
	return;
}


//成绩功能界面
void menu5()
{
	cout << "\n\n\t\t成绩功能" << endl << endl;
	cout << "\t\t1、统计及格率" << endl << endl;
	cout << "\t\t2、各分数段人数" << endl << endl;
	cout << "\t\t3、返回" << endl << endl;
	return;
}


void window()
{
	int choice, choice1, choice2, choice3, choice4, choice5;
	function sims;
	while (1)
	{
		menu();
		cout << "请选择你要进行的操作：";
		cin >> choice;
		while (choice != 6)
		{
			while (choice <= 0 || choice > 6)
			{
				cout << "输入有误，请重新输入！";
				cin >> choice;
			}
			switch (choice)
			{
			case 1:
				while (1)
				{
					menu1();
					cout << "请输入要进行的操作：";
					cin >> choice1;
					if (choice1 == 1)
					{
						sims.add();
						cout << "\n\n\n\t\t学生成绩信息表（更新）" << endl;
					}
					if (choice1 == 2)
					{
						// 返回
						system("cls");
						window();
					}
					break;
				}break;
			case 2:
				while (1)
				{
					menu2();
					cout << "请输入要进行的操作：";
					cin >> choice2;
					if (choice2 == 1)
					{
						sims.Del();
						cout << "\n\n\n\t\t学生成绩信息表（更新）" << endl;
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
					cout << "请输入要进行的操作：";
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
					cout << "请输入要进行的操作：";
					cin >> choice4;
					if (choice4 == 1)
					{
						sims.show();
					}
					if (choice4 == 2)
					{
						// 统计人数
						cout << endl;
						cout << "\t\t=======显示学生总人数=======" << endl;
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
					cout << "请输入要进行的操作：";
					cin >> choice5;
					if (choice5 == 1)
					{
						double  jiege;
						jiege = sims.getpassrate();
						cout << endl;
						cout << "\t\t=======及格率=======" << endl;
						cout << "\t\t 及格率为：" << jiege*100 <<"%"<< endl;
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