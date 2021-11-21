#include "romans.h"
#include <cstring>
#include <iostream>

using namespace std;
void romans::data()
{
	cout << "���: " << fio << endl;
	cout << "���� �����: " << years << endl;
	cout << "������������: " << books << endl;
	cout << "������� ���������: " << bio << endl;
	
}

void romans::set()
{
	while (1)
	{
		system("cls");
		cout << "������� ������ �����(������ ��������, ������� ������ ������������� _ ): ";
		cin >> fio;
		if (exception(fio) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ����� �����(������ ��������, ������� ������ ������������� _ ): ";
		cin >> years;
		if (exception(years) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ��� ������� �����(������ ��������, ������� ������ ������������� _ ): ";
		cin >> books;
		if (exception(books) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ����� ��������(������ ��������, ������� ������ ������������� _ ): ";
		cin >> bio;
		if (exception(bio) == -2)
			continue;
		break;
	}
}

void romans::recover(ifstream& fin)
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
		case 3:
		{
			bio = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void romans::save(ofstream& out)
{
	out << 2 << endl;
	out << fio << endl;
	out << years << endl;
	out << books << endl;
	out << bio << endl;
}

romans::romans()
{
	fio = "��� ����������";
	years = "��� ����������";
	books = "��� ����������";
	bio = "��� ����������";

}

romans::romans(string k, string �, string t, string h)
{
	fio = k;
	years = �;
	books = t;
	bio = h;
}

romans::romans(const romans& romans) :
	fio(romans.fio), years(romans.years), books(romans.books), bio(romans.bio) {}

romans::~romans() {}

int romans::exception(string line)
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
			cout << "������ ���� �� ����� ���� ������!" << endl;
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