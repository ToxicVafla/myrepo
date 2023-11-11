#include <iostream>
#include <conio.h>
#include "Header.h"

using namespace std;

int main()
{
	cout << "Select the test(press a number from 1 to 6) or smth else to end" << endl;
	while (true) {
		switch (_getch())
		{
		case '1':
			cout << "TEST1 ";
			Test("TEST1.txt");
			break;
		case '2':
			cout << "TEST2 ";
			Test("TEST2.txt");
			break;
		case '3':
			cout << "TEST3 ";
			Test("TEST3.txt");
			break;
		case '4':
			cout << "TEST4 ";
			Test("TEST4.txt");
			break;
		case '5':
			cout << "TEST5 ";
			Test("TEST5.txt");
			break;
		case '6':
			cout << "TEST6 ";
			Test("TEST6.txt");
			break;
		default:
			return 0;
		}
	}
}
