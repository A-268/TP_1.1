#pragma once
#include "Check.h"
#include "Array.h"

using namespace std;

class Note
{
private:
	string surname, name, phonenumber;
	int birthdate[3];
public:
	Note();
	Note(string surname, string name, int birthdate[3], string phonenumber);
	Note(const Note& note);
	~Note();

	void inputFromConsole();
	void printToConsole();
	void change();

	string getSurname() { return surname; }
	void setSurname(string surname) { this->surname = surname; }

	string getName() { return name; }
	void setName(string name) { this->name = name; }

	int* getBirthdate() { return birthdate; }
	void setBirthdate(const int birthdate[3]) { this->birthdate[0] = birthdate[0]; this->birthdate[1] = birthdate[1]; this->birthdate[2] = birthdate[2]; }

	string getPhonenumber() { return phonenumber; }
	void setPhonenumber(string phonenumber) { this->phonenumber = phonenumber; }

	Note& operator=(const Note& note);
	bool operator>(Note& note);
};
