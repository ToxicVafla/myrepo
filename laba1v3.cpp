#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double x, y, z, g, e;
/*
    x = 12.3*pow(10, -1); // 1.23
    y = 15.4;
    z = 0.252 * pow(10, 3); //252            
    g = 82.8257;
   */
    const double pi = 3.1415926;

    cout << "Введите x, y, z" << endl;
   // ;

    if (cin >> x >> y >> z)
    {
        if ((x + y) == 0 || sin(z) == 0)
        {
            cout << "На ноль делить нельзя, попробуйте ещё раз с другими числами";
            return 0;
        }

        if ((y == 0) && (x + 1 == 0))
        {
            cout << "Ноль в нулевой степени не имеет смысла";
            return 0;
        }

        if ((modf(x + 1, &e) != 0 && y < 0) || (modf(-1 / sin(z), &e) != 0 && x + 1 < 0))
        {
            cout << "Нельзя возводить отрицательное число в дробную степень";
            return 0;
        }

        g = pow(y, x + 1) / (pow(abs(y - 2), 1.0 / 3) + 3) + (x + y / 2) / (2 * abs(x + y)) * pow(x + 1, -1 / sin(z));
        cout << g;
    }
    else
    {
        cout << "Вы ввели не числовое значение";
        return 0;
    }
    return 0;
}