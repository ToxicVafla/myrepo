#include <iostream>
#include <math.h>
#include <conio.h>
#include <ctime>
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
int vvoddlyarazmera()                                                                  //отдельный ввод, чтобы не целочисленный размер массива не округлялся
{
    int vvoddlyarazmera;
    cin >> vvoddlyarazmera;
    while (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' '))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Нечисловое значение и/или вы ввели не целое значение размера массива, попробуйте ещё раз" << endl;
        cin >> vvoddlyarazmera;
    }
    return vvoddlyarazmera;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    cout << "Введите желаемое количество элементов массива(< 21): ";                                    //выбираем кол-во элементов
    const int a = vvoddlyarazmera();                                                                    //проверки за выход из возможного диапазона
    if (a == 0)
    {
        cout << "Что мне искать в пустом массиве????????";
        return 0;
    }
    if (a < 0)
    {
        cout << "Как вы себе представляете массив с отрицательным колиеством элементов!?";
        return 0;
    }
    if (a > 20)
    {
        cout << "Вы ввели больше 20 элементов, не соответствует условию задания";
        return 0;
    }
    double *array = new double[a];
    cout << "Нажмите 1 если желаете ввести элементы сами, или нажмите любую клавишу для автозаполенения массива числами[-100;100]" << endl;             //выбираем способ заполнения массива
    if (_getch() == '1')
    {
        cout << "Введите элементы массива" << endl;                                        //создание массива с элем3етами пользователя
        for (int i = 0; i < a; i++)
        {
            array[i] = vvod();
        }

        for (int l = 0; l < a; l++)
        {
            cout << array[l] << " ";
        }
        cout << "- ваш массив" << endl;
    }
    else
    {
        for (int j = 0; j < a; j++)                                           //создание массива с рандомными значениями
        {
            array[j] = rand() % 201 + (-100);                               //второе число в выражении rand это минимальная граница - (-100),
            cout << array[j] << " ";                                        //а результат самого выражения -1 это верхний предел - (201 - 100 - 1 = 100)
        }
        cout << '\n';
    }
    int nummin = 0;                                                         //находим последний минимальный по модулю элемент
    double min = array[0];
    for (int k = 1; k < a; k++)
    {
        if (abs(array[k]) <= abs(min))
        {
            min = array[k];
            nummin = k;
        }
    }
    cout << min << " - это наименьший по модулю элемент" << endl;
    double summ = 0;
    for (int n = (nummin + 1); n < a; n++)                                   //считаем сумму модулей элементов после последнего минимального по модулю
    {
        summ += abs(array[n]);
    }
    cout << "Сумма модулей элементов после последнего наименьшего по модулю элемента = " << summ << endl;
    delete [] array;
}