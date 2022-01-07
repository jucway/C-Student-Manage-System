#include <iostream>
#include"student.h"
#include"window.h"
using namespace std;
void student::setid(int id)
{
	stu_id = id;
}
void student::setname(char* name)
{
	stu_name = name;
}
void student::setgender(char gender)
{
	stu_gender = gender;
}
void student::show(ostream& out)const
{
	out << stu_id << '\t';
	out << stu_name << '\t';
	out << stu_gender << '\t';
}

int student::getid()const
{
	return stu_id;
}
char* student::getname()const
{
	
	char *buffer = {};
    buffer = stu_name;

	return buffer;
}
char student::getgender()const
{
	return stu_gender;
}
SIMS::SIMS(long int id, char* name, char gender, int score) :student(id, name, gender)
{
	this->stu_score = score;
	if (stu_score < 0 || stu_score>100)
	{
		rank = '0', stu_score = 0;
	}
	else
		if (stu_score >= 0 && stu_score < 60)
			rank = 'D';
		else if (stu_score >= 60 && stu_score < 80)
			rank = 'C';
		else if (stu_score >= 80 && stu_score < 90)
			rank = 'B';
		else if (stu_score >= 90 && stu_score <= 100)
			rank = 'A';
}
void SIMS::set(int id, char* name, char gender, int score)
{
	student::setname(name);
	student::setgender(gender);
	student::setid(id);
	stu_score = score;
	if (stu_score < 0 || stu_score>100)
	{
		rank = '0', stu_score = 0;
	}
	else if (stu_score >= 0 && stu_score < 60)
		rank = 'D';
	else if (stu_score >= 60 && stu_score < 80)
		rank = 'C';
	else if (stu_score >= 80 && stu_score < 90)
		rank = 'B';
	else if (stu_score >= 90 && stu_score <= 100)
		rank = 'A';
}
void SIMS::set(const SIMS& stu)
{
	student::setname(stu.student::getname());
	student::setgender(stu.student::getgender());
	student::setid(stu.student::getid());
	stu_score = stu.stu_score;
	rank = stu.rank;
}
ostream& operator<<(ostream& out, const SIMS& stu)
{
	stu.student::show(out);
	out << stu.stu_score << '\t';
	out << stu.rank << '\t';
	return out;
}

istream& operator>>(istream& in, SIMS& stu)
{
	in >> stu.stu_id;
	in.get(stu.stu_name, 20);
	in >> stu.stu_gender;
	return in;
}
int SIMS::getscore()
{
	return stu_score;
}
//�����ȼ�
char SIMS::getrank()
{
	return rank;
}
void SIMS::infile(ifstream & in)
{
	string buffer;
	in >> stu_id; in >> buffer;
	stu_name = new char[strlen(buffer.c_str()) + 1];
	strcpy(stu_name, buffer.c_str());
	in >> stu_gender;
	in >> stu_score;
	in >> rank;
}
void SIMS::outfile(ofstream& out)
{
	out << "  " << stu_id << ' \t' << stu_name << '\t\t' << stu_gender << '\t' << stu_score <<'\t'<<rank<< endl;

}
void SIMS::out()
{
	cout << stu_id << "\t" << stu_name << "\t" << stu_gender << "\t" << stu_score <<'\t'<<rank<<endl;
}
function::function()
{
	stu_first = new SIMS;
	read();
}
function::~function()
{
	delete stu_first;
}
void function::add()
{
	int id; 
	//char name[20]; 
	char gender; int score;
	SIMS* f, * p, * q;
	system("cls");
	f = stu_first;
	q = stu_first->next;
	p = new SIMS;
	cout << "������Ҫ���ѧ������Ϣ��" << endl;
	cout << "������Ҫ���ѧ��ѧ�ţ�";
	cin >> id;
	while (q)
	{
		if (id == p->getid())
		{
			cout << "��ѧ���Ѵ��ڣ����������룡\n\n";
			cin >> id;
			break;
		}
		q = q->next;
	}
	cout << "������������";
	
	char* name = new char[20];
	cin >> name;
	cout << "�������Ա�";
	cin >> gender;
	cout << "������ɼ���";
	cin >> score;
	p->set(id, name, gender, score);
	f->next = p;
	p->next = NULL;

	f = f->next;
	save();
	count++;
}
void function::Del()
{
	char name[20]; int id;	char choose;
	SIMS* temp, * p;
	system("cls");
	p = temp = stu_first->next;
	cout << "����������Ҫɾ��ѧ����ѧ�ź�������";
	cin >> id >> name;
	while (temp)
	{
		if (strcmp(temp->getname(), name) == 0 && temp->getid() == id)
		{
			cout << "ѧ��\t����\t�Ա�\t�ɼ�\n";
			temp->out();
			cout << "\n�Ƿ�ɾ������ѧ����Ϣ��y/n)";
			cin >> choose;
			if (choose == 'y' || choose == 'Y')
			{
				p->next = temp->next;
				delete temp;
				count--;
				cout << "ɾ���ɹ���\n";
			}
			break;
		}
		p = temp;
		temp = temp->next;
	}
	//save();
	cout << "1���������˵�\n2.����ɾ��" << endl;
	cin >> choose;
	while (choose != '1' && choose != '2')
	{
		cout << "1.�������˵�\n2.����ɾ��" << endl;
		cin >> choose;
	}
	if(choose=='1')
	{
		window();
	}
	if (choose == '2')
		Del();
}
void function::read()
{
	SIMS* p, * q;
	p = stu_first;
	ifstream in("C:\\Users\\HP\\Desktop\\rec\\student.txt", ios::in);
	if (!in.is_open())
	{
		cout << "can not open this file" << endl;
	}
	if (!in)
	{
		ofstream out("C:\\Users\\HP\\Desktop\\rec\\student.txt", ios::out);
		out.close();
		return;
	}
	while (!in.eof() && in.peek() != EOF)
	{
		q = new SIMS;
		q->infile(in);
		count+=1;
		p->next = q;
		q->next = NULL;
		p = p->next;
	}
}
void function::save()
{
	if (stu_first != NULL)
	{
		SIMS* p = stu_first->next;
		while (p != NULL)
		{
			char name[20]; char gender; int id; int score;
			id = p->getid();
			score = p->getscore();
			char rak;
			if (score >= 90 && score < 100)
			{
				rak = 'A';
			}
			else if (score >= 80 && score < 90)
			{
				rak = 'B';
			}
			else if (score >= 70 && score < 80)
			{
				rak = 'C';
			}
			else if (score >= 60 && score < 70)
			{
				rak = 'D';
			}
			else if  (score < 60 && score >0)
			{
				rak = 'E';
			}
			strcpy(name, p->getname());
			gender = p->getgender();

			fstream file;
			file.open("C:\\Users\\HP\\Desktop\\rec\\student.txt", std::ios::app);
			file << endl;
			file << id << "\t" << name << "\t\t" << gender << "\t" << score <<'\t'<<rak<<endl;
			//file.write((char*)&id, 4);
			//file.write(name, 7);
			//file.write((char*)&gender, 3);
			//file.write((char*)&score, 4);
			p = p->next;
		}
	}
}
void function::search_byid()
{
	int flag(0);
	int id;
	system("cls");
	SIMS* temp = stu_first->next;
	cout << "������Ҫ����ѧ��ѧ�ţ�";
	cin >> id;
	while (temp)
	{
		if (id == temp->getid())
		{
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	if (flag == 0)
		cout << "���޸�ѧ����\n" << endl;
	else
	{
		cout << "ѧ��\t����\t�Ա�\t�ɼ�\n";
		temp->out();
	}
}
void function::search_byname()
{
	int flag(0);
	char name[20];
	system("cls");
	SIMS* temp = stu_first->next;
	cout << "������Ҫ����ѧ��������";
	cin >> name;
	while (temp)
	{
		if (strcmp(name, temp->getname()) == 0)
		{
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	if (flag == 0)
		cout << "���޸�ѧ����\n" << endl;
	else
	{
		cout << "ѧ��\t����\t�Ա�\t�ɼ�\n";
		temp->out();
	}
}
void function::showCount()
{
	cout << "��ǰѧ��������Ϊ��" << count << endl;
}
void greate60()
{
	// ����60
}
void function::show()
{
	char choose;
	SIMS* temp;
	system("cls");
	temp = stu_first->next;
	if (!temp)
	{
		cout << "�ļ�������\n\n" << endl;
		cout << "1.�������˵�" << endl;
		cin >> choose;
		while (choose != '1')
		{
			cout << "1.�������˵�" << endl;
			cin >> choose;
			
		}
		window();
	}
	else
	{
		cout << "ѧ��\t����\t\t�Ա�\t�ɼ�\t�����ȼ�\n";
		while (temp != NULL)
		{
			temp->out();
			temp = temp->next;
		}
		//cout << endl;
		//cout << "\t��ǰѧ�������ܹ��У� " << count << "��" << endl;
	}
}
double function::getpassrate()
{
	SIMS* temp;
	temp = stu_first;
	double i = 0;
	while (temp != NULL)
	{
		if (temp->getscore() >= 60)
			i = i + 1;
		temp = temp->next;
	}
	passrate = i / count;
	if (stu_first == NULL || count == 0)
		return 0;
	else
		return passrate;
}
void function::showinfo()
{
	num1 = 0; num2 = 0; num3 = 0; num4 = 0;
	SIMS* p = stu_first;
	while (p != NULL)
	{
		int i = p->getscore();
		if (i >= 90 && i <= 100)
			num1++;
		if (i >= 80 && i < 90)
			num2++;
		if (i >= 60 && i < 80)
			num3++;
		if (i >= 0 && i < 60)
			num4++;
		p = p->next;
	}
	cout << "A�ȼ���90-100�����У�  " << num1++ << "\n";
	cout << "B�ȼ���80-90�����У�  " << num2++ << "\n";
	cout << "C�ȼ���60-80�����У�  " << num3++ << "\n";
	cout << "D�ȼ���0-60�����У�  " << num4++ << "\n";
}