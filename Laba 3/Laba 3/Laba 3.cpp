#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <iostream>
using namespace std;

int Fib_R(int n);
int Fib_Ordinary(int n);

int main()
{
	int n;
	cout << "Enter n:" << endl;
	cin >> n;

	int functionType;
	cout << "Choose function:" << endl;
	cout << "1. Recursive" << endl;
	cout << "2. Non-recursive" << endl;
	cin >> functionType;

	switch (functionType) {
	case 1:
		cout << Fib_R(n) << endl;
		break;
	case 2:
		cout << Fib_Ordinary(n) << endl;
		break;
	default:
		cout << "Input correct number" << endl;
	}


}

int Fib_R(int n) {

	if (n == 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}

	return Fib_R(n - 1) + Fib_R(n - 2);
}
int Fib_Ordinary(int n) {

	if (n == 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}

	int Previous = 1;
	int Current = 1;

	for (int i = 2; i < n; i++) {
		int temp = Previous;
		Previous = Current;
		Current = Previous + temp;

	}
	return Current;
}