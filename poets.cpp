#include "poets.h"
#include <iostream>
#include <cstring>

using namespace std;

void poets::data()
{
	cout << "���: " << fio << endl;
	cout << "���� �����: " << years << endl;
	cout << "������������: " << books << endl;
}

void poets::set()
{
	while (1)
	{
		system("cls");
		cout << "������� ��� ��������(������ ��������, ������� ������ ������������� _ ): ";
		cin >> fio;
		if (exception(fio) == -2)
			continue;
		break;
	}
	while(1)
	{
		system("cls");
		cout << "������� ���� ����� ��������(������ ��������, ������� ������ ������������� _ ): ";
		cin >> years;
		if (exception(years) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� �������� ������������ ��������(������ ��������, ������� ������ ������������� _ ): ";
		cin >> books;
		if (exception(books) == -2)
			continue;
		break;
	}
}

void poets::recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 4; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			fio = line;
			break;
		}
		case 1:
		{
			years = line;
			break;
		}
		case 2:
		{
			books = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void poets::save(ofstream& out)
{
	out << 3 << endl;
	out << fio << endl;
	out << years << endl;
	out << books << endl;
}

poets::poets()
{
	fio = "��� ����������";
	years = "��� ����������";
	books = "��� ����������";
}

poets::poets(string fio, string years, string books)
{
	this->fio = fio;
	this->years = years;
	this->books = books;
}

poets::poets(const poets& poets) : fio(poets.fio), years(poets.years), books(poets.books) {}

int poets::exception(string line)
{
	try
	{
		if (line.empty())
			throw -2;
	}
	catch (int a)
	{
		switch (a)
		{
		case -2:
		{
			cout << "�������� ������ ��������� ������!" << endl;
			system("pause");
			return -2;
		}
		default:
		{
			cout << "���-�� ����� �� ���!" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}

poets::~poets() {}


