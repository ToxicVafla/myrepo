#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;
/*
void clear(string path)
{
	ofstream file(path);
	
	string str;
	file << str;

	file.close();
}
*/
void record(string path1)
{
	ofstream file(path1);
	cout << "Recording str..." << endl;
	
	string str;
	string cipher;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if ((i+1) % 2 == 0)
		{
			cipher += str[i];
			str[i] = '1';
		}
	}
	
	file << str << '\n';
	file << cipher;
	
	cout << "Done!" << endl;
	file.close();
}

void read(string path)
{
	ifstream file(path);
	string str;
	string cipher;
	getline(file, str);
	getline(file, cipher);
	int counter = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if ((i + 1) % 2 == 0)
		{
			str[i] = cipher[counter];
			counter++;
		}
	}

	cout << str << endl;
	
	file.close();
}

void wcipher(string path)
{
	ifstream file(path);
	string str;
	string cipher;
	getline(file, str);
	getline(file, cipher);
	cout << "Str with cipher - " << str << endl;;
	cout << "cipher - " << cipher << endl;
	file.close();

}
int main()
{
	string path1("C:\\Users\\vasil\\Desktop\\1.txt");
	//getline(cin, path);
	int key = 0;
	do {
		cout << "Choose operation,\ntype \"1\" to read file\ntype \"2\" to record smth in file\ntype \"3\" to watch file with cipher" << endl;
		switch (_getch())
		{
		case '1':
		{
			read(path1);
			break;
		}
		case '2':
		{
			record(path1);
			break;
		}
		case '3':
		{
			wcipher(path1);
			break;
		}
		default:
		{
			cout << "Wrong input" << endl;
		}
		}
		cout << "Wanna do more? Press \"n\" to end, press smth else to continue" << endl;
		if (_getch() == 'n')
		{
			key = 1;
		}
	} while (key == 0);
}