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
	int getid()const;//���ѧ��
	char* getname()const;//�������
	char getgender()const;//����Ա�
	virtual void show(ostream& out)const;//��ʾѧ����Ϣ
protected: // ��������Ϊprotected ���ںͼ̳ж����Է��� 
	long int stu_id;    //ѧ��
	char* stu_name;    //����
	char stu_gender;     //�Ա�


};

class SIMS :public student
{
protected:
	int stu_score;
	char rank;
public:
	SIMS() {};
	SIMS(long int id, char* name, char gender, int score);
	~SIMS() {}   //��������
	void set(int id, char* name, char gender, int score);
	void set(const SIMS& stu);
	friend ostream& operator<<(ostream& out, const SIMS& stu);//����������
	friend istream& operator >> (istream& input, SIMS& stu);
	int getscore();//��óɼ�
	char getrank();//���������ȼ�
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
	void read();//��ȡ��Ϣ
	void save();//����ѧ����Ϣ
	void add();//���ѧ����Ϣ
	void search_byid();//ͨ��ѧ�Ų���
	void search_byname();//ͨ��������
	void Del();//ɾ��ѧ����Ϣ
	void show();//��ʾѧ����Ϣ
	void showCount();

	double getpassrate();//���㼰����
	void showinfo();//��ʾ������������
private:
	SIMS* stu_first;
	int count;
	double passrate;
	int num1, num2, num3, num4;
};
