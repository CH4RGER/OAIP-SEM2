#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <Windows.h>
#include <iterator>

using namespace std;

struct sotrudnik {
	string fio;
	int nomer;
	int chas;
	int tarif;
	double zarplata;
};

vector<sotrudnik> sotrudniks;
double zarplata;
//int l = 0;
//int r = sotrudniks.size() - 1;
void ReadSotrudniksDataFromFile();
void SaveSotrudniksToFile();
void AddSotrudnik();
void RemoveSotrudnik();
void PrintSotrudnikData();
void EditSotrudnik();
void ShowMenu();
void Search();
void Quick_Sort(vector<sotrudnik>& a, int begin, int end);
int bsearch(vector<sotrudnik>& a, int key, int first, int last);
void PrintSotrudnikDataSearch();



void ReadSotrudniksDataFromFile()
{
	ifstream infile("Sotrudniks.txt");
	string line;
	while (getline(infile, line))
	{
		istringstream ss(line);
		string point;
		sotrudnik member;

		getline(ss, point, ';');
		member.fio = point;

		getline(ss, point, ';');
		member.nomer = stoi(point);

		getline(ss, point, ';');
		member.chas = stoi(point);

		getline(ss, point, ';');
		member.tarif = stoi(point);

		getline(ss, point, ';');
		member.zarplata = stod(point);

		

		sotrudniks.push_back(member);
	}



}

void SaveSotrudniksToFile()
{
	ofstream output_file("Sotrudniks.txt");
	for (int i = 0; i < sotrudniks.size(); i++) {

		output_file << sotrudniks[i].fio << ';';
		output_file << sotrudniks[i].nomer << ';';
		output_file << sotrudniks[i].chas << ';';
		output_file << sotrudniks[i].tarif << ';';
		output_file << sotrudniks[i].zarplata << ';';


		if (i != sotrudniks.size() - 1) {
			output_file << endl;
		}

	}


}

void EditSotrudnik()
{
	while (true)
	{
		cout << "1. Add Sotrudnik" << endl;
		cout << "2. Remove Sotrudnik" << endl;
		cout << "3. Exit to main menu" << endl;
		int choice;
		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
			AddSotrudnik();
			break;
		case 2:
			RemoveSotrudnik();
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}


void AddSotrudnik() 
{
	cout << "Enter product info" << endl;

	sotrudnik member;

	cout << "Vvedite dannye sotrudnika:" << endl;
	cout << "FIO: " << endl;
	cin.ignore();
	getline(cin, member.fio);
	puts("Tabelnuy nomer: ");
	cin >> member.nomer;
	puts("Otrabotanuj chasov: ");
	cin >> member.chas;
	puts("Tarif: ");
	cin >> member.tarif;

	if (member.chas > 144)
	{
		member.zarplata = member.tarif * (2 * member.chas - 144) * 0.88;
	}
	else
	{
		member.zarplata = member.tarif * member.chas * 0.88;
	}

	sotrudniks.push_back(member);
	SaveSotrudniksToFile();
	cout << "Sotrudnik added" << endl;

}

void RemoveSotrudnik()
{
	system("cls");
	while (true)
	{
		int choice2;
		cout << "Input\n1. to continue removing\n2. to exit to edit menu" << endl;
		cin >> choice2;

		switch (choice2)
		{
		case 1:
		{
			system("cls");
			cout << "--------- Select index of Sotrudnik To Remove ---------" << endl;
			PrintSotrudnikData();
			int i;
			cin >> i;
			sotrudniks.erase(sotrudniks.begin() + (i - 1));
			break;
		}
		case 2:
			system("cls");
			return;
		default:
			cout << "Input the correct number\n";
			break;

		}
	}
	SaveSotrudniksToFile();

}

void PrintSotrudnikData() {

	cout << "\n----------------------- Sotrudniks -----------------------" << endl;
	for (int i = 0; i < sotrudniks.size(); i++)
	{
		cout << i + 1 << endl;
		cout << "FIO: " << sotrudniks[i].fio << endl;
		cout << "ID number: " << sotrudniks[i].nomer << endl;
		cout << "Amount of hours: " << sotrudniks[i].chas << endl;
		cout << "Tarif: " << sotrudniks[i].tarif << endl;
		cout << "Zarplata: " << sotrudniks[i].zarplata << endl;

		cout << "--------------------------------------------------------" << endl;

	}

}

void Search()
{
	
	
	while (true)
	{
		cout << "1. Search Pryamo" << endl;
		cout << "2. Search Dvoichno" << endl;
		cout << "3. Exit to main menu" << endl;
		

		int choice;

		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
			cout << "Vvedite zarplatu" << endl;
			cin >> zarplata;
			PrintSotrudnikDataSearch();
			break;
		case 2:
			
			Quick_Sort(sotrudniks, 0, sotrudniks.size() - 1);
			PrintSotrudnikData();
			/*bsearch(sotrudniks, zarplata, 0, sotrudniks.size() - 1);*/
			
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}

void PrintSotrudnikDataSearch() {
	int count = -1;
	cout << "\n----------------------- Sotrudniks -----------------------" << endl;
	for (int i = 0; i < sotrudniks.size(); i++)
	{
		if (zarplata == sotrudniks[i].zarplata)
		{
			cout << i + 1 << endl;
			cout << "FIO: " << sotrudniks[i].fio << endl;
			cout << "ID number: " << sotrudniks[i].nomer << endl;
			cout << "Amount of hours: " << sotrudniks[i].chas << endl;
			cout << "Tarif: " << sotrudniks[i].tarif << endl;
			cout << "Zarplata: " << sotrudniks[i].zarplata << endl;
			cout << "--------------------------------------------------------" << endl;
			count++;
		}
		
	}
	if (count == -1)
	cout << "no sotrudnik found\n" << endl;
}

void Quick_Sort(vector<sotrudnik>& a, int begin, int end)
{
	int i, j;
	sotrudnik x;
	i = begin;
	j = end;
	x = a[(i + j) / 2];
	sotrudnik buff;
	do
	{
		while (a[i].fio[0] < x.fio[0])
		{
			i++;
		}
		while (a[j].fio[0] > x.fio[0])
		{
			j--;
		}


		if (i <= j)
		{
			buff = a[i];
			a[i] = a[j];
			a[j] = buff;
			i++;
			j--;
		}

	} while (i <= j);
	if (begin < j) { Quick_Sort(a, begin, j); }
	if (end > i)
	{
		Quick_Sort(a, i, end);
	}
}

int bsearch(vector<sotrudnik>& a, int key, int first, int last)
{
	cout << "Vvedite zarplatu" << endl;
	cin >> zarplata;
	bool flag = false;
	int l = first; // левая граница
	int r = last; // правая граница
	int mid;

	while ((l <= r) && (flag != true)) {
		mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

		if (sotrudniks[mid].zarplata == zarplata) flag = true; //проверяем ключ со серединным элементом
		if (sotrudniks[mid].zarplata > zarplata) r = mid - 1; // проверяем, какую часть нужно отбросить
		else l = mid + 1;
	}

	if (flag)
		cout << endl << mid + 1 << endl
		<< "FIO: " << sotrudniks[mid].fio << endl
		<< "ID number: " << sotrudniks[mid].nomer << endl
		<< "Amount of hours: " << sotrudniks[mid].chas << endl
		<< "Tarif: " << sotrudniks[mid].tarif << endl
		<< "Zarplata: " << sotrudniks[mid].zarplata << endl
		<< "--------------------------------------------------------" << endl;
	else cout << "no sotrudnik found" << endl;
	return 0;
}

void ShowMenu()
{
	while (true)
	{
		cout << "1. Show Sotrudniks" << endl;
		cout << "2. Edit Students" << endl;
		cout << "3. Search" << endl;
		cout << "4. Exit" << endl;

		int choice;

		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
			PrintSotrudnikData();
			break;
		case 2:
			EditSotrudnik();
			break;
		case 3:
			Search();
			break;
		case 4:
			exit(1);
		default:
			break;
		}
	}
}


int main()
{
	ReadSotrudniksDataFromFile();
	ShowMenu();
}


