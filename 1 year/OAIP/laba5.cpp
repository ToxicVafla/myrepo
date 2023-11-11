#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

double input()
{
    double input;
    cin >> input;
    while (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' '))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Не числовое значние, попробуйте ещё раз" << endl;
        cin >> input;
    }
    return input;
}

int input_for_matrix()
{
    int input;
    cin >> input;
    while (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' '))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Не числовое и/или не целое значние, попробуйте ещё раз" << endl;
        cin >> input;
    }

    while (input < 0)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Введите положительное число" << endl;
        cin >> input;
    }
    return input;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");

    cout << "Задание : поменять строку с максимальным элементом и строку с минимальным элементом" << endl;
    cout << "Введите количество строк" << endl;
    int strnum = input_for_matrix();
    cout << "Введите количество столбцов" << endl;
    int boldnum = input_for_matrix();
    
    double** array = new double* [strnum];                   //объявление двумерного динамического массива
    for (int i = 0; i < strnum; i++)
    {
        array[i] = new double[boldnum];
    }

    cout << "Нажмите 1 если желаете ввести элементы сами, или нажмите любую клавишу для автозаполенения массива числами[-100;100]" << endl;     //выбираем способ заполнения массива
    
    if (_getch() == '1')
    {
        for (int i = 0; i < strnum; i++)                    //задание элементов массива самостоятельно
        {
            for (int j = 0; j < boldnum; j++)
            {
                cout << "Введите элемент " << i + 1 << " строки " << j + 1 << " столбца" << endl;
                array[i][j] = input();
            }
        }
    }
    else                                                    
    {
        for (int i = 0; i < strnum; i++)                     //задание элементов массива случайными числами
        {
            for (int j = 0; j < boldnum; j++)
            {
                array[i][j] = rand() % 201 + (-100);
            }
        }
    }

    double counter_for_max = array[0][0];                       //переменные для нахождения min и max и их положения в матрице
    int num_of_str_with_max = 0;
    
    double counter_for_min = array[0][0];
    int num_of_str_with_min = 0;
    
    cout << '\n' << "Ваш массив(матрица):" << endl;     
    cout << "-----------------------------------------------------" << endl;
    for (int i = 0; i < strnum; i++)                            //вывод введённого массива
    {
        for (int j = 0; j < boldnum; j++)
        {
            cout << array[i][j] << "  ";
            
            if (array[i][j] >= counter_for_max)                 //находим max и номер его строки
            {
                counter_for_max = array[i][j];
                num_of_str_with_max = i;
            }

            if (array[i][j] <= counter_for_min)                 //находим min и номер его строки
            {
                counter_for_min = array[i][j];
                num_of_str_with_min = i;
            }
        }
        cout << '\n';
    }
    cout << "-----------------------------------------------------" << endl;

    cout << '\n' << counter_for_max << " - max    " << num_of_str_with_max + 1 << " - num of str with max" << '\n' << counter_for_min << " - min    " << num_of_str_with_min + 1;
    cout << " - num of str with min" << '\n' << endl;

    if (num_of_str_with_max == num_of_str_with_min)
    {
        cout << "Максимальный и минимальный элементы находятся в одной строке, соответственно нет смысла менять строки" << endl;
        return 0;
    }

    for (int j = 0; j < boldnum; j++)                       //меняем местам строки
    {                                                                           //меняем местами строки без использования буферной строки таким способом:
        array[num_of_str_with_max][j] += array[num_of_str_with_min][j];         //  a = a + b
        array[num_of_str_with_min][j] -= array[num_of_str_with_max][j];         //  b = b - a
        array[num_of_str_with_min][j] = -(array[num_of_str_with_min][j]);       //  b = -b
        array[num_of_str_with_max][j] -= array[num_of_str_with_min][j];         //  a = a - b
    }                                                                           //итог: значения b и a поменялись
    
    cout << "Конечный массив:" << endl;
    cout << "-----------------------------------------------------" << endl;

    for (int i = 0; i < strnum; i++)                        //вывод конечного массива
    {
        for (int j = 0; j < boldnum; j++)
        {
            cout << array[i][j] << "  ";
        }
        cout << '\n';
    }
    cout << "-----------------------------------------------------" << endl;

    for (int i = 0; i < strnum; i++)                        //освобождение памяти
    {
        delete[] array[i];
    }
    delete[] array;
}