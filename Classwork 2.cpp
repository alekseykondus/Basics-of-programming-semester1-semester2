#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <direct.h> 
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

struct vocabulary
{
	char ENG[20];
	char UA[20];
};
void out_RED(const char str[100])
{
	SetConsoleTextAttribute(console, FOREGROUND_RED);
	cout << str << endl;
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}
void out_GREEN(const char str[100])
{
	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
	cout << str << endl;
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}
int input1_2_3(char(&a)[100])
{
	if (a[0] == 49)
		return 1;
	else if (a[0] == 50)
		return 2;
	else if (a[0] == 51)
		return 3;
	else
	{
		out_RED("Номер функции введен не правильно!");
		return 0;
	}
}
int input1_2(char(&a)[100])
{
	if (a[0] == 49)
		return 1;
	else if (a[0] == 50)
		return 2;
	else
	{
		out_RED("Номер функции введен не правильно!");
		return 0;
	}
}

bool b1(char* mas1, char* mas2, int n)
{
	for (int i = 0; i < n; i++)
		if (mas1[i] != mas2[i])
			return 0;
	return 1;
}
void addnew(vocabulary& dict, char a[100])
{
	cout << "Введите английский вариант слова: ";
	cin.ignore(32767, '\n');
	cin.getline(dict.ENG, 20, '\n');
	cout << "Введите украинский вариант слова: ";
	cin.ignore(32767, '\n');
	cin.getline(dict.UA, 20, '\n');

	FILE* voc;
	if (fopen_s(&voc, a, "a+b"))
		perror("Error");
	else
		fwrite(&dict, sizeof(dict), 1, voc);
	fclose(voc);
	out_GREEN("Слово успешно добавлено");
}
void tr(vocabulary& dict1, char a[100])
{
	FILE* voc;
	vocabulary dict2;
	cout << "Введите английский вариант слова: ";
	cin.ignore(32767, '\n');
	cin.getline(dict1.ENG, 20, '\n');
	if (fopen_s(&voc, a, "rb"))
		perror("Error");
	else
	{
		while (!feof(voc))
		{
			fread(&dict2, sizeof(dict2), 1, voc);
			if (feof(voc))
				break;
			if (b1(dict1.ENG, dict2.ENG, size(dict1.ENG)))
				cout << dict2.UA << endl;
		}
	}
	fclose(voc);
}
void out(char a[100])
{
	FILE* voc;
	vocabulary dict2;
	if (fopen_s(&voc, a, "rb"))
		perror("Error");
	else
	{
		fread(&dict2, sizeof(dict2), 1, voc);
		cout << "Первая запись: " << endl
			<< dict2.ENG << endl << dict2.UA << endl;

		while (!feof(voc))
		{
			fread(&dict2, sizeof(dict2), 1, voc);
			if (feof(voc))
			{
				cout << endl << "Последня запись: " << endl
					<< dict2.ENG << endl << dict2.UA << endl;
				break;
			}
		}
	}
	fclose(voc);
}
bool pause()
{
	while (1)
	{
		cout << "Желаете продолжить работу с переводчиком?" << endl
			<< "1 - ДА" << endl << "2 - НЕТ" << endl << "_______" << endl;
		char s[100];
		cin >> s;

		int k;
		k = input1_2(s);
		switch (k)
		{
		case 1:
			return 1;
			break;
		case 2:
			return 0;
			break;
		default:
			break;
		}
	}
}
int main()
{
	_mkdir("dictionary");
	char a[100] = "dictionary\\vocabulary";
	setlocale(LC_ALL, "");
	vocabulary dict;
	int k;
	bool b = 1;
	while (b)
	{
		cout << "Что хотите сделать?" << endl
			<< "1 - Добавить новое слово" << endl << "2 - Узнать перевод слова" << endl << "3 - Посмотреть первую и последнюю запись" << endl
			<< "________________________________________" << endl;
		char s[100];
		cin.ignore(32767, '\n');
		cin.getline(s, 100, '\n');
		k = input1_2_3(s);
		switch (k)
		{
		case 1:
			addnew(dict, a);
			b = pause();
			break;
		case 2:
			tr(dict, a);
			b = pause();
			break;
		case 3:
			out(a);
			b = pause();
			break;
		default:
			break;
		}
	}
	out_GREEN("Хорошего дня!");
}
