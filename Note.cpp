#include "Note.h"

Note::Note() : surname("Не задано"), name("Не задано"), phonenumber("Не задано")
{
	birthdate[0] = 0;
	birthdate[1] = 0;
	birthdate[2] = 0;
	cout << "  Вызван конструктор Note" << endl;
}

Note::Note(string surname, string name, int birthdate[3], string phonenumber) :
	surname(surname), name(name), phonenumber(phonenumber)
{
	setBirthdate(birthdate);
	cout << "  Вызван конструктор Note" << endl;
}

Note::Note(const Note& note) : surname(note.surname), name(note.name), phonenumber(note.phonenumber)
{
	setBirthdate(note.birthdate);
	cout << "  Вызван конструктор копирования Note" << endl;
}

Note::~Note()
{
	cout << "  Вызван деструктор Note" << endl;
}

void Note::inputFromConsole()
{
	cout << "  Введите фамилию: ";
	getline(cin, surname);
	cout << "  Введите имя: ";
	getline(cin, name);
	cout << "  Введите дату рождения:\n";
	cout << "  Число: ";
	birthdate[0] = safeInput(1, 31);
	cout << "  Месяц: ";
	birthdate[1] = safeInput(1, 12);
	cout << "  Год: ";
	birthdate[2] = safeInput(1, INT32_MAX);
	phonenumber = inputPhoneNumber();
}

void Note::printToConsole()
{
	cout << "  Фамилия и имя: " << surname ;
	cout << " " << name << endl; 
	cout << "  Дата рождения: " << birthdate[0] << "." << birthdate[1] << "." << birthdate[2] << endl;
	cout << "  Номер телефона: " << phonenumber << endl;
}

void Note::change()
{
	cout << "  Введите новую фамилию: ";
	getline(cin, surname);
	cout << "  Введите новое имя: ";
	getline(cin, name);
	cout << "  Введите новую дату рождения:\n";
	cout << "  Число: ";
	birthdate[0] = safeInput(1, 31);
	cout << "  Месяц: ";
	birthdate[1] = safeInput(1, 12);
	cout << "  Год: ";
	birthdate[2] = safeInput(1, INT32_MAX);
	phonenumber = inputPhoneNumber();
	cout << endl;
}

Note& Note::operator=(const Note& note) 
{
	if (this == &note)
		return *this;
	surname = note.surname;
	name = note.name;
	phonenumber = note.phonenumber;
	setBirthdate(note.birthdate);
	return *this;
}

bool Note::operator>(Note& note) 
{
	return (birthdate[2] > note.birthdate[2]) || (birthdate[2] == note.birthdate[2] && birthdate[1] > note.birthdate[1]) || (birthdate[2] == note.birthdate[2] && birthdate[1] == note.birthdate[1] && birthdate[0] > note.birthdate[0]);
}
