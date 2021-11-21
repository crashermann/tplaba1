#include "fantasts.h"
#include <iostream>
#include <cstring>
using namespace std;

void fantasts::data()
{
	cout << "ФИО: " << fio << endl;
	cout << "Произведения: " << books << endl;
	cout << "Фильмы по произведениям: " << films << endl;
}

void fantasts::set()
{
	while (1)
	{
		system("cls");
		cout << "Введите ФИО писателя(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> fio;
		if (exception(fio) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите произведения писателя(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> books;
		if (exception(books) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите фильмы, снятые по произведениям писателя(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> films;
		if (exception(films) == -2)
			continue;
		break;
	}
}

void fantasts::recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 3; i++)
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
			books = line;
			break;
		}
		case 2:
		{
			films = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void fantasts::save(ofstream& out)
{
	out << 1 << endl;
	out << fio << endl;
	out << books << endl;
	out << films << endl;
}

fantasts::fantasts()
{
	fio = "Нет информации";
	books = "Нет информации";
	films = "Нет информации";
}

fantasts::fantasts(string k, string c, string t)
{
	fio = k;
	books = c;
	films = t;
}

fantasts::fantasts(const fantasts& fur) :
	fio(fur.fio), books(fur.books), films(fur.films){}

fantasts::~fantasts() {}

int fantasts::exception(string line)
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
			cout << "Данное поле не может быть пустым!!!" << endl;
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