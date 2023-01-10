#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

double doubleinput()
{
    double input;
    cin >> input;
    while (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' '))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Нечисловое значение, попробуйте ещё раз" << endl;
        cin >> input;
    }
    return input;
}

int intinput()
{
    int input;
    cin >> input;
    while (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' '))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Нечисловое значение, попробуйте ещё раз" << endl;
        cin >> input;
    }
    return input;
}

int factorial(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

double y(double a)
{
    return 1. / 2 * (exp(a) - exp(-a));
}

double s(double a, double n)
{
    double summ = 0.0;
    for (int i = 0; i <= n; i++)
    {
        summ += (pow(a, 2 * i + 1) / factorial(2 * i + 1));
    }
    return summ;
}

double y_minus_s(double a, int n)
{
    double y_minus_s = 0;
    y_minus_s = fabs(y(a) - s(a, n));
    return y_minus_s;
}


void Out_Rez(double a, double b, double h, int n)
{
    int switch_key = 0;
    do {
        int key = intinput();
        switch (key) {
        case 1: {
            cout << "Y(x)" << endl;
            for (a; a <= b; a += h)
            {
                cout << y(a) << endl;
            }
            switch_key++;
            break;
        }
        case 2: {
            cout << "S(x)" << endl;
            for (a; a <= b; a += h)
            {
                cout << s(a, n) << endl;
            }
            switch_key++;
            break;
        }
        case 3: {
            cout << "|Y(x)-S(x)|" << endl;
            for (a; a <= b; a += h)
            {
                cout << y_minus_s(a, n) << endl;
            }
            switch_key++;
            break;
        }
        default: {
            cout << "Введите 1, 2 или 3" << endl;
            break;
        }
        }
    } while (switch_key == 0);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int key_for_rep = 0;
    do {

        cout << "Введите a, b, h ,n (1, 10, 1, 5)" << endl;
        double a, b, h;
        int n;
        a = doubleinput();
        b = doubleinput();
        h = doubleinput();
        n = intinput();

        cout << "Выберите номер действия, которое хотите выполнить" << endl;
        cout << "1. Y(x)" << endl;
        cout << "2. S(x)" << endl;
        cout << "3. |Y(x)-S(x)|" << endl;
        Out_Rez(a, b, h, n);
        cout << "\nНажмите '1', если хотите выполнить ещё одно действие, иначе нажмите любую клавишу" << endl;
        if (_getch() != '1')
        {
            key_for_rep = 1;
        }
        cout << '\n';
    } while (key_for_rep == 0);
}