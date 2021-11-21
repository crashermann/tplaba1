#include "romans.h"
#include <cstring>
#include <iostream>

using namespace std;
void romans::data()
{
	cout << "ФИО: " << fio << endl;
	cout << "Годы жизни: " << years << endl;
	cout << "Произведения: " << books << endl;
	cout << "Кратная биография: " << bio << endl;
	
}

void romans::set()
{
	while (1)
	{
		system("cls");
		cout << "Введите породу птицы(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> fio;
		if (exception(fio) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите окрас птицы(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> years;
		if (exception(years) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите тип питания птицы(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> books;
		if (exception(books) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите место обитания(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
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
	fio = "Нет информации";
	years = "Нет информации";
	books = "Нет информации";
	bio = "Нет информации";

}

romans::romans(string k, string с, string t, string h)
{
	fio = k;
	years = с;
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
			cout << "Данное поле не может быть пустым!" << endl;
			system("pause");
			return -2;
		}
		default:
		{
			cout << "Что-то пошло не так!" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}