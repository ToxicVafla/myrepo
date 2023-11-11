#include <iostream>
#include <math.h>
using namespace std;

double vvod()
{
    double vvod;
    cin >> vvod;
    while (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' '))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Нечисловое значение, попробуйте ещё раз" << endl;
        cin >> vvod;
    }
    return vvod;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double x, y;
    const double pi = 3.1415926;
    cout << "Введите x, y" << endl;
    x = vvod();
    y = vvod();
    
    if (x > 0 && y >= 0)
    {
        cout << max(x, y + sqrt(x)) << endl;
    }
    else
    {
        if (x < 0)
        {
            cout << min(x, y) + pow(sin(x), 2) - pow(cos(y), 2) << endl;
        }
        else
        {
            cout << 0.5 * x + exp(y) << endl;
        }
    }
    
    
    return 0;
}

double max(double a, double b)
{
    if (a > b) return a;
    if (b >= a) return b;
}

double min(double a, double b)
{
    if (a > b) return b;
    if (b >= a) return a;
}

