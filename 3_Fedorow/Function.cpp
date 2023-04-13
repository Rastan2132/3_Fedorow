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
void dell(Uzond*& program, short* size, short* size_of_people)
{
	cout << "Usunąć użytkownika lub użytkownika? (u lub o)" << endl;
	switch (_getch()) {
	case (117):
	{
		if (*size <= 0) {
			error();
		}
		cout << "Wybierz numer Uzond, który chcesz usunąć (1 - " << *size << "):" << endl;
		int num = 0;
		cin >> num;
		if (num < 1 || num > *size) {
			error();
		}

		(*size)--;
		Uzond* program_n = new Uzond[*size];
		for (int i = 0, j = 0; i < *size + 1; i++) {
			if (i != num - 1) {
				program_n[j] = program[i];
				j++;
			}
		}
		delete[] program[num - 1].getPeople();
		program = program_n;
		break;
	}

	case (111):
	{
		if (*size_of_people <= 0) {
			error();
		}

		cout << "Wybierz numer użytkownika, którego chcesz usunąć(1 - " << *size_of_people << "):" << endl;
		int num = 0;
		cin >> num;
		if (num < 1 || num > *size_of_people) {
			error();
		}

		for (int i = 0; i < *size; i++) {
			Users** new_people = new Users * [*size_of_people - 1];
			for (int j = 0, k = 0; j < *size_of_people; j++) {
				if (j != num - 1) {
					new_people[k] = program[i].getPeople()[j];
					k++;
				}
			}
			delete[] program[i].getPeople();
			program[i].setPeople(new_people, *size_of_people);
		}
		(*size_of_people)--;
		break;
	}
	}
}

void edit(Uzond*& program, short index_1, short index_2)
{
	system("cls");
	ShowCursor(1);
	if (index_1 < 0 || index_2 < 0)
	{
		error();
	}
	string line;
	string name = "", surname = " ", Year = " ", Piesel = " ", Sex = " ";
	cout << "Wstępne dane:" << endl;
	cout << MANIP << program[index_1].getPeople()[index_2]->Name << " " << MANIP << program[index_1].getPeople()[index_2]->Surname << " " << MANIP << program[index_1].getPeople()[index_2]->Year << " " << MANIP << program[index_1].getPeople()[index_2]->piesel << " " << MANIP << program[index_1].getPeople()[index_2]->sex << " ";
	cout << endl;
	bool valid_input = false;
	cout << "Podaj Name Surname Year Pesel i sex: ";
	while (!valid_input) {

		string line;

		getline(cin, line);
		name = line.substr(0, line.find_first_of(";"));
		line = line.substr(line.find_first_of(";") + 1);
		surname = line.substr(0, line.find_first_of(";"));
		line = line.substr(line.find_first_of(";") + 1);
		Year = line.substr(0, line.find_first_of(";"));
		line = line.substr(line.find_first_of(";") + 1);
		Piesel = line.substr(0, line.find_first_of(";"));
		line = line.substr(line.find_first_of(";") + 1);
		Sex = line.substr(0, line.find_first_of(";"));

		bool name_is_alpha = true, surname_is_alpha = true, sex_is_alpha = true, Year_is_digit = true, Piesel_is_digit = Piesel.size() == 12;
		if (line.size() > 1) {
			for (char c : name)
				if (!isalpha_r(c)) {
					name_is_alpha = false;
					break;
				}
			for (char c : surname)
				if (!isalpha_r(c)) {
					surname_is_alpha = false;
					break;
				}
			for (char c : Sex)
				if (!isalpha_r(c)) {
					sex_is_alpha = false;
					break;
				}
			for (char c : Year) {
				if (!isdigit_r(c)) {
					Year_is_digit = false;
					break;
				}
			}
			for (char c : Piesel)
				if (!isdigit_r(c)) {
					Piesel_is_digit = false;
					break;
				}

			if (!name_is_alpha || !surname_is_alpha || !sex_is_alpha || !Year_is_digit || !Piesel_is_digit)
			{
				error();
			}
			else {
				program[index_1].getPeople()[index_2]->Name = name;
				program[index_1].getPeople()[index_2]->Surname = surname;
				program[index_1].getPeople()[index_2]->Year = Year;
				program[index_1].getPeople()[index_2]->piesel = Piesel;
				program[index_1].getPeople()[index_2]->sex = Sex;
				valid_input = true;
			}
		}
	}
	ShowCursor(0);
}