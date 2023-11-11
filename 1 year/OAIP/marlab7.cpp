#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

void record(string path)
{
    setlocale(LC_ALL, "Russian");
    ofstream fout;

    fout.open(path);
    if (!fout.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else
    {
        cout << "Введите строку" << endl;
        string str;
        getline(cin, str);
        fout << str;
    }
    fout.close();
}
void read(string path)
{
    ifstream fin;
    fin.open(path);
    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else
    {
        string str;
        getline(fin, str);
        cout << str << endl;   
    }
    fin.close();
}
void encryption(string path)
{
    ifstream fin(path);
    string str;
    string cipher;
    getline(fin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if ((i + 1) % 2 == 0)
        {
            cipher += str[i];
            str[i] = '1';
        }
    }
    fin.close();
    ofstream fout(path);
    fout << str << endl;
    fout << cipher;
    fout.close();
    cout << "Зашифровка выполнена!" << endl;
}
void decoding(string path)
{

    ifstream fin(path);
    string str;
    string cipher;
    getline(fin, str);
    getline(fin, cipher);
    int counter = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if ((i + 1) % 2 == 0)
        {
            str[i] = cipher[counter];
            counter++;
        }
    }

    fin.close();
    ofstream fout(path);
    fout << str;
    fout.close();
    cout << "Расшифровка выполнена!" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string path("myFile.txt");
    int key = 0;
    do {
        cout << "Выберите номер действия, которое хотите выполнить" << endl;
        cout << "1. Ввод с клаиватуры исходной строки текста и запись в файл" << endl;
        cout << "2. Считывание строки из файла и вывод на экран" << endl;
        cout << "3. Зашифровать" << endl;
        cout << "4. Расшифровать" << endl;
        switch (_getch())
        {
        case '1':
        {
            record(path);
            break;
        }
        case '2':
        {
            read(path);
            break;
        }
        case '3':
        {
            encryption(path);
            break;
        }
        case '4':
        {
            decoding(path);
            break;
        }
        default:
        {
            cout << "Неверный ввод" << endl;
        }
        }
        cout << "\nНажмите '1', если хотите выполнить ещё одно действие, иначе нажмите любую клавишу" << endl;
        if (_getch() != '1')
        {
            key = 1;
        }
    } while (key == 0);
}