#pragma once
#pragma warning (disable:4996)
#include <fstream>
#include<iostream>
using namespace std;

class student
{
public:
	student() {};
	student(long int id, char* name, char gender) {
		stu_name = new char[20];
		stu_id = id;
		stu_name = name;
		stu_gender = gender;
	}
	~student() {
		delete[] stu_name;
	}
	void setname(char* name);
	void setgender(char gender);
	void setid(int id);
	int getid()const;//获得学号
	char* getname()const;//获得姓名
	char getgender()const;//获得性别
	virtual void show(ostream& out)const;//显示学生信息
protected: // 这里设置为protected 类内和继承都可以访问 
	long int stu_id;    //学号
	char* stu_name;    //姓名
	char stu_gender;     //性别


};

class SIMS :public student
{
protected:
	int stu_score;
	char rank;
public:
	SIMS() {};
	SIMS(long int id, char* name, char gender, int score);
	~SIMS() {}   //析构函数
	void set(int id, char* name, char gender, int score);
	void set(const SIMS& stu);
	friend ostream& operator<<(ostream& out, const SIMS& stu);//操作符重载
	friend istream& operator >> (istream& input, SIMS& stu);
	int getscore();//获得成绩
	char getrank();//计算优良等级
	SIMS* next;
	void out();
	void infile(ifstream& in);
	void outfile(ofstream& out);
};

class function
{
public:
	function();
	~function();
	void read();//读取信息
	void save();//保存学生信息
	void add();//添加学生信息
	void search_byid();//通过学号查找
	void search_byname();//通姓名查找
	void Del();//删除学生信息
	void show();//显示学生信息
	void showCount();

	double getpassrate();//计算及格率
	void showinfo();//显示各分数段人数
private:
	SIMS* stu_first;
	int count;
	double passrate;
	int num1, num2, num3, num4;
};
