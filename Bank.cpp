// Bank_client : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Bank_Client
{
	string fio;
	string bank_type;
	string account_number;
	double money;
	int data[9];
};

int Menu();

void File_name(string&, const string);
void Check(fstream&, string);
void Create(string);
void Add(string);
void Input(fstream&);
bool Input(Bank_Client&);
void View(string);
void Task(string);
void Task(char*, double, double);
void Change(char*, double&);
void Output(string);

int main()
{
	setlocale(LC_ALL, "RU");

	Bank_Client* array;
	int size, i;
	string fname;

	File_name(fname, "input name of data file:\n");

	

	while (true)
	{
		switch (Menu())
		{
		case 1: File_name(fname, "Введите имя файла данных:\n");
			break;
		case 2: Create(fname);
			break;
		case 3: Add(fname);
			break; 
		case 4:  View(fname);
			break; 
		case 5:  Task(fname);
		    break; 
		case 6:  Output(fname);
			break;
		case 7:
			break;
		case 0:
			return 0;
		}
	}
}

int Menu()
{
	int choose;

	do
	{
		cout << "Режимы работы с файлом:\n";
		cout << "1 - Ввод имени файла\n";
		cout<<  "2 - Создание файла\n";
		cout << "3 - Добавление данных в файл\n";
		cout << "4 - Просмотр файла\n";
		cout << "5 - Задание\n";
		cout << "6 - Запись результата\n";
		cout << "0 - Выход\n";

		cout << "Выберите режим работы:\n";
		cin >> choose;
	} while (choose<0 || choose>6);

	return choose;
}

void File_name(string& fname, const string text)
{
	cout << text;
	rewind(stdin);
	getline(cin, fname);
}

void Check(fstream& file, string fname)
{
	if (!file)
	{
		cerr << "\nОшибка открытия файла "<<fname<<endl;
	}
}
void Input(fstream& file)
{
	Bank_Client temp;

	while (Input(temp))
		file.write(reinterpret_cast <char*>(&temp), sizeof(temp));
}

void Create(string fname)
{
	fstream out(fname, "ios::out");

	Check(out, fname);

	Input(out);

	out.close();
}

void Add(string)
{
	fstream file(fname, "ios::app");

	Check(file, fname);

	Input(file);

	file.close();
}

bool Input(Bank_Client& temp)
{
	int j;
	string fio;

	cout << "\nВведите ФИО:\n";
	rewind(stdin);
	getline(cin, fio);

	if (!fio.length())
		return false;

	temp.fio = fio;

	cout << "\nВведите тип счета:\n";
	rewind(stdin);
	cin >> temp.bank_type;

	cout << "\nВведите номер счета:\n";
	rewind(stdin);
	cin >> temp.account_number;

	cout << "\nВведите сумму на счете (BYN):\n";
	rewind(stdin);
	cin >> temp.money;

	cout << "\nВведите дату последнего изменения:\n";
	rewind(stdin);
	cout << "Число:";
	for (j = 0; j < 3; j++)
	{
		switch (j)
		{
		case 1:
			cout << "Месяц:";
			break;
		case 2:
			cout << "Год:";
		}
		cin >> temp.data[j];
	}
	return true;
}


void View(string fname)
{
	char* temp;

	fstream in(fname, "ios::in");

	Check(in, fname);

	in.read(reinterpret_cast <char*>(&temp), sizeof(temp));
	while (!in.eof())
	{
		cout << temp;
		in.read(reinterpret_cast <char*>(&temp), sizeof(temp));
	}
	cout << endl;

	in.close();
}

void Change(char* temp, double &money)
{

}

void Task(string fname)
{
	char* temp;
	double min, max;

	cout << "\nВведите диапазон суммы" << endl;
	cout << "от ";
	cin >> min;
	cout << "\nдо ";
	cin >> max;

	fstream in(fname, "ios::in");

	Check(in, fname);

	in.read(reinterpret_cast <char*>(&temp), sizeof(temp));
	while (!in.eof())
	{
		Task(temp, min, max);
		in.read(reinterpret_cast <char*>(&temp), sizeof(temp));
	}
	cout << endl;

	in.close();
}

void Output(string)
{

}


void View(Bank_Client& bank_client)
{
	int j;

	cout << setw(15) << bank_client.fio
		<< setw(15) << bank_client.bank_type
		<< setw(15) << bank_client.account_number
		<< setw(15) << bank_client.money << " BYN" << setw(15);

	for (j = 0; j < 3; j++)
	{
		if (j <= 1)
			cout << bank_client.data[j] << ". ";
		else
			cout << bank_client.data[j];
	}
}

void Task(char* temp, double min, double max)
{
	bool flag;

	flag = false;

	Change(temp, money);
		if (money >= min && money <= max)
		{
			if (!flag)
			{
				flag = true;
				cout << "Клиенты банка, с суммой на счету, входящей в заданный диапазон:" << endl;
			}
			View(array[i]);
		}
	}
	if (!flag)
		cout << "\nТаких клиентов нет.\n";
}
