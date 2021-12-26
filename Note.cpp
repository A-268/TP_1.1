#include "Note.h"

Note::Note() : surname("�� ������"), name("�� ������"), phonenumber("�� ������")
{
	birthdate[0] = 0;
	birthdate[1] = 0;
	birthdate[2] = 0;
	cout << "  ������ ����������� Note" << endl;
}

Note::Note(string surname, string name, int birthdate[3], string phonenumber) :
	surname(surname), name(name), phonenumber(phonenumber)
{
	setBirthdate(birthdate);
	cout << "  ������ ����������� Note" << endl;
}

Note::Note(const Note& note) : surname(note.surname), name(note.name), phonenumber(note.phonenumber)
{
	setBirthdate(note.birthdate);
	cout << "  ������ ����������� ����������� Note" << endl;
}

Note::~Note()
{
	cout << "  ������ ���������� Note" << endl;
}

void Note::inputFromConsole()
{
	cout << "  ������� �������: ";
	getline(cin, surname);
	cout << "  ������� ���: ";
	getline(cin, name);
	cout << "  ������� ���� ��������:\n";
	cout << "  �����: ";
	birthdate[0] = safeInput(1, 31);
	cout << "  �����: ";
	birthdate[1] = safeInput(1, 12);
	cout << "  ���: ";
	birthdate[2] = safeInput(1, INT32_MAX);
	phonenumber = inputPhoneNumber();
}

void Note::printToConsole()
{
	cout << "  ������� � ���: " << surname ;
	cout << " " << name << endl; 
	cout << "  ���� ��������: " << birthdate[0] << "." << birthdate[1] << "." << birthdate[2] << endl;
	cout << "  ����� ��������: " << phonenumber << endl;
}

void Note::change()
{
	cout << "  ������� ����� �������: ";
	getline(cin, surname);
	cout << "  ������� ����� ���: ";
	getline(cin, name);
	cout << "  ������� ����� ���� ��������:\n";
	cout << "  �����: ";
	birthdate[0] = safeInput(1, 31);
	cout << "  �����: ";
	birthdate[1] = safeInput(1, 12);
	cout << "  ���: ";
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
