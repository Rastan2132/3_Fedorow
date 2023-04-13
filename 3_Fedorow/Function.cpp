#include "Header.h"

void error()
{
	Beep(800, 150);
	cout << "ERROR!" << endl << endl;
	system("pause");
}

bool isdigit_r(unsigned char a) { return (a >= '0' && a <= '9'); }
bool isalpha_r(unsigned char a)
{
	bool rez = ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || a == '-');

	return rez;
}

Uzond* create(int size, int people_size) {
	Uzond* arr = new Uzond[size];
	for (int i = 0; i < size; i++) {
		Users** people = new Users * [people_size];
		for (int j = 0; j < people_size; j++) {
			people[j] = new Users();
		}
		arr[i].setPeople(people, people_size);
	}
	return arr;
}


void initRand(Uzond*& program, short size, short size_of_peopl, vector<string> arr_name, vector<string> arr_suname, vector<string>arr_of_name_urzant)
{
	for (int i = 0; i < size; i++) {
		program[i].setName(arr_of_name_urzant[rand() % 4]);
		program[i].setNumer(rand_data(num_));

		for (int j = 0; j < size_of_peopl; j++) {
			program[i].getPeople()[j] = new Users;
			program[i].getPeople()[j]->sex = rand_data(sex_);
			program[i].getPeople()[j]->Name = arr_name[rand_data(program[i].getPeople()[j]->sex)];
			program[i].getPeople()[j]->Surname = arr_suname[rand_data(program[i].getPeople()[j]->sex)];
			program[i].getPeople()[j]->Year = rand_data(year_);
			program[i].getPeople()[j]->piesel = rand_data(piesel_);
		}
	}
}

int rand_data(string sex)								/// от 0 до 9 муж. от 10 до 19 жен
{
	if (sex == "man")
		return rand() % 5;
	else
		return rand() % 5 + 5;

}
string rand_data(int max)
{
	string rez;
	if (max == 2)
	{
		if ((rand() % 2) == 1)
		{
			rez = "man";
		}
		else
		{
			rez = "women";
		}
		return rez;
	}
	else if (max == 4)
	{
		int year = rand() % (2023 - 1900 + 1) + 1900;
		return to_string(year);
	}
	else if (max == 12)
	{
		unsigned int number = 0;
		for (int i = 0; i < 12; i++) {
			number = number * 10 + rand() % 10;
		}

		return to_string(number);
	}
	else if (max == 3)
	{
		long long number = 0;
		for (int i = 0; i < 3; i++) {
			number = number * 10 + rand() % 10;
		}
		return to_string(number);
	}
	return nullptr;
}

void show(Uzond* program, short size, short size_of_peopl)
{
	system("cls");
	cout << "----------------------------------------------------------------------------------------------------\n";
	cout << MENU << endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	cout << "                              ---=== UZOND BOOK ===---            your Uzond: " << size << endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	cout << stru << endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	for (short i = 0; i < size; i++)
	{
		cout << right << setw(3) << setfill('0') << i + 1 << setfill(' ') << " ";
		cout << MANIP << program[i].getName() << " " << MANIP << program[i].getNumer() << endl;
		cout << endl << " ";
		for (short j = 0; j < size_of_peopl; j++)
		{
			cout << right << setw(3) << setfill('0') << j + 1 << setfill(' ') << " " << MANIP << program[i].getPeople()[j]->Name << " " << MANIP << program[i].getPeople()[j]->Surname << " " << MANIP << program[i].getPeople()[j]->Year << " " << MANIP << program[i].getPeople()[j]->piesel << " " << MANIP << program[i].getPeople()[j]->sex << " ";
			cout << endl << " ";
		}
		cout << endl << endl;
	}
}
void add(Uzond*& program, short* size, short* size_of_peopl, vector<string> arr_name, vector<string> arr_suname, vector<string>arr_of_name_urzant)
{
	cout << "Сhcesz dodać urzond lub osobę(u lub o)" << endl;
	Uzond* program_n = nullptr;
	switch (_getch())
	{
	case (117): {
		(*size)++;
		program_n = new Uzond[*size];
		for (int i = 0; i < *size - 1; i++) {
			Users** people = new Users * [*size_of_peopl];
			for (int j = 0; j < *size_of_peopl; j++) {
				people[j] = new Users();
			}
			program_n[i].setPeople(program[i].getPeople(), *size_of_peopl);
			program_n[i].setName(program[i].getName());
			program_n[i].setNumer(program[i].getNumer());
		}
		Users** people = new Users * [*size_of_peopl];
		for (int j = 0; j < *size_of_peopl; j++) {
			people[j] = new Users();
			people[j]->sex = rand_data(sex_);
			people[j]->Name = arr_name[rand_data(people[j]->sex)];
			people[j]->Surname = arr_suname[rand_data(people[j]->sex)];
			people[j]->Year = rand_data(year_);
			people[j]->piesel = rand_data(piesel_);
		}
		program_n[*size - 1].setPeople(people, *size_of_peopl);
		program_n[*size - 1].setNumer(rand_data(num_));
		program_n[*size - 1].setName(arr_of_name_urzant[rand() % 4]);

		delete[] program;
		program = program_n;

		break;
	}
	case (111):
		(*size_of_peopl)++;
		program_n = new Uzond[*size];
		for (int i = 0; i < *size; i++) {
			Users** people = new Users * [*size_of_peopl];
			for (int j = 0; j < *size_of_peopl - 1; j++) {
				people[j] = program[i].getPeople()[j];
			}
			people[*size_of_peopl - 1] = new Users();
			people[*size_of_peopl - 1]->sex = rand_data(sex_);
			people[*size_of_peopl - 1]->Name = arr_name[rand_data(people[*size_of_peopl - 1]->sex)];
			people[*size_of_peopl - 1]->Surname = arr_suname[rand_data(people[*size_of_peopl - 1]->sex)];
			people[*size_of_peopl - 1]->Year = rand_data(year_);
			people[*size_of_peopl - 1]->piesel = rand_data(piesel_);
			program_n[i].setPeople(people, *size_of_peopl);
			program_n[i].setName(program[i].getName());
			program_n[i].setNumer(program[i].getNumer());
		}
		delete[] program;
		program = program_n;
		break;
	}
}