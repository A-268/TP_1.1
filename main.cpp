#include <fstream>
#include <Windows.h>
#include "Array.h"
#include "Note.h"

using namespace std;

void printMenu();
void addNote(Array<Note>& notes);
void changeNote(Array<Note>& notes);
void deleteNote(Array<Note>& notes);
void print(Array<Note>& notes);
void searchNote(Array<Note>& notes);

int main() 
{
	setlocale(LC_ALL, "Russian");
	Array<Note> notes;
	bool isExit = false;
	while (!isExit) 
	{
		printMenu();
		int method = safeInput(1, 6);
		switch (method)
		{
		case 1:
			addNote(notes);
			break;
		case 2:
			changeNote(notes);
			break;
		case 3:
			deleteNote(notes);
			break;
		case 4:
			print(notes);
			break;
		case 5:
			searchNote(notes);
			break;
		case 6:
			isExit = true;
			break;
		}
	}
}

void printMenu() 
{
	cout << endl;
	cout << "     ���� ���������: " << endl;
	cout << "  1. �������� ������" << endl;
	cout << "  2. �������� ������" << endl;
	cout << "  3. ������� ������" << endl;
	cout << "  4. ������� ������" << endl;
	cout << "  5. ����� �� ����� ���������� � ��������, ��� ������� ������� � ����������" << endl;
	cout << "  6. �����" << endl;
	cout << "  \n  �������� ����� ����: ";
}

void addNote(Array<Note>& notes) 
{
	Note note;
	note.inputFromConsole();
	notes += note;
}

void changeNote(Array<Note>& notes) 
{
	if (notes.getSize() > 0) 
	{
		print(notes);
		cout << "  ������� ����� ������ ��� ���������: ";
		notes[safeInput(1, notes.getSize()) - 1].change();
	}
	else
		cout << "  ������ ����!\n";
}

void deleteNote(Array<Note>& notes) 
{
	if (notes.getSize() > 0) 
	{
		print(notes);
		cout << "  ������� ����� ������ ��� ��������: ";
		notes -= safeInput(1, notes.getSize()) - 1;
	}
	else
		cout << "  ������ ����!\n";
}

void print(Array<Note>& notes) 
{
	if (notes.getSize() == 0)
		cout << "  ������ ����!\n";
	else 
	{
		cout << "  ������ �������:\n";
		for (int i = 0; i < notes.getSize(); i++) 
		{
			cout << "  ";
			cout << i + 1 << ". ������\n";
			notes[i].printToConsole();
		}
	}
}

void searchNote(Array<Note>& notes)
{
	if (notes.getSize() == 0)
		cout << "  ������ ����!\n";
	else 
	{
		bool isPrint = false;
		cout << "  ������� ������ �������: ";
		string surname;
		getline(cin, surname);
		for (int i = 0; i < notes.getSize(); i++)
			if (notes[i].getSurname() == surname)
			{
				isPrint = true;
				notes[i].printToConsole();
			}
		if (!isPrint)
			cout << "  �� �������!\n";
	}
}