#include <iostream>
#include<conio.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int rand_();
void show_menu();
void write(vector <int> &v);
//
void main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	char k;
	bool key = 1;
	int size = 10;

	do
	{
		system("cls");
		show_menu();
		cin >> k;		
		if (k<'0' || k>'2')
		{
			cout << "\t\tError!!!" << endl;
		}
		else
		{
			switch (k)
			{
			case '1':
			{

				int num = 0;
				vector <int> v1;
				for (int i = 0; i < size; i++)
				{
					num = rand_();
					cout << setw(5) << num;
					v1.push_back(num * num);
				}
				cout << endl << endl;
				//for (int i = 0; i < v1.size(); i++)
				//{
				//	cout << setw(5) << v1[i];
				//}
				for (auto it  = v1.begin(); it!=v1.end(); it++)
				{
					cout << setw(5) << *it;
				}
				cout << "\n\n\t\t\t\tНажмите пробел, чтоы продолжить" << endl;
				_getch();
			}break;
			case '2':
			{
				vector< vector <int> > v2;
				cout << "\t\tТаблица умножения:" << endl;
				cout << "---------------------------------------------------" << endl;
				for (int i = 0; i < size; i++)
				{
					v2.push_back(vector<int>());
					for (int j = 0; j < size; j++)
						v2[i].push_back((i + 1) * (j + 1));
				}

				for (int i = 0; i < size; i++)
				{
					for (int j = 0; j < size; j++)
						cout << setw(5) << v2[i][j];

					cout << endl << endl;
				}
				cout << "\n\n\t\t\t\tНажмите пробел, чтоы продолжить" << endl;
				_getch();
			}break;
			case '0':
			{
				key = 0;
			}break;
			default:
				break;
			}
		}
		
	} while (key);
	
	cout << "\n\n\t\t\t\t\tThe End!" << endl;
}
//
int rand_()
{
	int n = rand()%30+1;
	return n;
}

void show_menu()
{
	cout << "\t\t\t\tДомашнее задание №20" << endl << endl;
	cout << "1 - Заполнить вектор длинной 10 квадратами целых чисел и вывести его в выходной поток." << endl;
	cout << "2 - Заполнить двухмерный вектор таблицей умножения и вывести его в выходной поток." << endl;
	cout << "0 - Выход" << endl << endl;
	cout << "Enter:";
}

void write(vector <int>& v)
{
	ofstream fout;
	fout.open("vec.txt", ios::out | ios::binary);
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout <<  *it<<"  ";
	}
	fout.close();
}

//cout << "Доп.задание: вывести вектор на внешний файл." << endl << endl;


