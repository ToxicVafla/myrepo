#include <iostream>
#include<ctime>
using namespace std;
int main()
{
    setlocale(0, "");
    int key;
    int n1 = 1, n2 = 1;   // Инициализация переменных (n1, n2 - мощность множеств 1 и 2 соответсвенно; 
    int* arr1 = new int[n1];    // Инициализация множества 1 с мощностью n1
    cout << "Выберите способ задания 1-ого множества\n";    // Ввод элементов 1-ого множества
    cout << "1. Высказыванием \n";
    cout << "2. Перечислением\n";
    cin >> key;
    if (key == 1) {
        cout << "Выберите высказывание для задания 1-ого множества\n";
        cout << "1. Высказывание 1\n";
        cout << "2. Высказывание 2\n";
        cin >> key;
        
        if (key == 1) {
            cout << "Введите значение n\n";    // Ввод мощности 1-ого множества при первом высказывании
            cin >> n1;
            arr1 = new int[n1];
            cout << "Первое множество: { ";
            for (int i = 0, k = 1; i < n1; i++, k++) {
                arr1[i] = 2 * k - 1;
                cout << arr1[i] << " ";
            }
            cout << "}\n";
        }
        else if (key == 2) {
            cout << "Введите значение m\n";    // Ввод мощности 1-ого множества при втором высказывании
            cin >> n1;
            arr1 = new int[n1];
            cout << "Первое множество: { ";
            for (int i = 0, r = 1; i < n1; i++, r++) {
                arr1[i] = 3 * r - 2;
                cout << arr1[i] << " ";
            }
            cout << "}\n";
        }
    }
    else if (key == 2) {
        cout << "Введите мощность 1-ого множества\n";    // Ввод мощности 1-ого множества при перечислении
        cin >> n1;
        arr1 = new int[n1];
        cout << "Введите элементы 1-ого множества\n";
        for (int i = 0; i < n1; i++) {
            cin >> arr1[i];
        }
    }
    cout << "Выберите способ задания 2-ого множества\n";    // Ввод элементов 2-ого множества
    cout << "1. Высказыванием\n";
    cout << "2. Перечислением\n";
    cin >> key;
    int* arr2 = new int[n2];    // Инициализация множества 2 с мощностью n2
    if (key == 1) {
        cout << "Выберите высказывание для задания 2-ого множества\n";
        cout << "1. Высказывание 1\n";
        cout << "2. Высказывание 2\n";
        cin >> key;
        
        if (key == 1) {
            cout << "Введите значение n\n";    // Ввод мощности 1-ого множества при первом высказывании
            cin >> n2;
            arr2 = new int[n2];
            cout << "Второе множество: { ";
            for (int i = 0, k = 1; i < n2; i++, k++) {
                arr2[i] = 2 * k - 1;
                cout << arr2[i] << " ";
            }
            cout << "}\n";
        }
        else if (key == 2) {
            cout << "Введите значение m\n";    // Ввод мощности 1-ого множества при втором высказывании
            cin >> n2;
            arr2 = new int[n2];
            cout << "Второе множество: { ";
            for (int i = 0, r = 1; i < n2; i++, r++) {
                arr2[i] = 3 * r - 2;
                cout << arr2[i] << " ";
            }
            cout << "}\n";
        }
    }
    else if (key == 2) {
        cout << "Введите мощность 2-ого множества\n";    // Ввод мощности 2-ого множества при перечислении
        cin >> n2;
        arr2 = new int[n2];
        cout << "Введите элементы 2-ого множества\n";
        for (int i = 0; i < n2; i++) {
            cin >> arr2[i];
        }
    }
    clock_t start = clock();
    //Операция объединение 
    //Задаём третье множество 
    int check = 0;
    for (int i = 0; i <= n1 - 1; i++) {
        for (int j = 0; j <= n2 - 1; j++) {
            if (arr1[i] == arr2[j]) {
                check++;
            }
        }
    }
    int sizeofunit = n1 + n2 - check;
    int* unit = new int[sizeofunit];
    //Продолжение выполнения операции объединения (по алгоритму)
    int limit = n1;
    for (int f = 0, i = 0; f <= (sizeofunit - 1); f++) {
        if (f <= (n1 - 1)) {
            unit[f] = arr1[f];
        }
        else {
            for (i; i <= n2 - 1; i++) {
                check = 0;
                for (int j = 0; j <= limit - 1; j++) {
                    if (arr2[i] == unit[j]) {
                        check++;
                        break;
                    }
                }
                if (check == 0) {
                    unit[f] = arr2[i];
                    limit++;
                    break;
                }
            }
            i++;
        }
    }
    cout << "\n";
    cout << "Результат обьединения: { "; // Вывод 3-его множества (результата обьединения) на экран
    for (int i = 0; i <= (sizeofunit - 1); i++) {
        cout << unit[i] << " ";
    }
    cout << "}";
    // Операция пересечение
    // Задаём четвёртое множество 
    int cross = 0;
    cout << "\n";
    for (int i = 0; i <= n1 - 1; i++) {
        for (int j = 0; j <= n2 - 1; j++) {
            if (arr1[i] == arr2[j]) {
                cross++;
            }
        }
    }
    int* crossing = new int[cross];
    //Продолжение выполнения операции пересечение (по алгоритму)
    cout << "\n";
    if (cross > 0) {
        cout << "Результат пересечения: { ";
        for (int i = 0, f = 0; i <= n1 - 1; i++) {
            for (int j = 0; j <= n2 - 1; j++) {
                if (arr1[i] == arr2[j]) {
                    crossing[f] = arr2[j];
                    cout << crossing[f] << " ";
                    f++;
                }
            }
        }
        cout << "}";
    }
    else {
        cout << "Пустое множество";
    }
    //Декартово произведение 1-ого множества со 2-ым множеством
    //Задаём пятое множество
    int size = 2 * n1 * n2;
    int* product1 = new int[size];
    int k = 0;
    cout << "\n";
    cout << "\n";
    //Продолжение операции декартово произведение (по алгоритму)
    cout << "Результат декартового произведения 1-ого со 2-ым: { ";
    for (int i = 0; i <= n1 - 1; i++) {
        for (int j = 0; j <= n2 - 1; j++, k++) {
            product1[k] = arr1[i];
            k++;
            product1[k] = arr2[j];
            if (j == (n2 - 1) && i == (n1 - 1)) {
                cout << "<" << product1[k - 1] << "," << product1[k] << "> ";
            }
            else {
                cout << "<" << product1[k - 1] << "," << product1[k] << ">, ";
            }
        }
    }
    cout << "}";
    //Декартово произведение 2-ого множества с 1-ым множеством
    //Задаём шестое множество
    int* product2 = new int[size];
    k = 0;
    cout << "\n";
    cout << "\n";
    //Продолжение операции декартово произведение (по алгоритму)
    cout << "Результат декартового произведения 2-ого с 1-ым: { ";
    for (int i = 0; i <= n2 - 1; i++) {
        for (int j = 0; j <= n1 - 1; j++, k++) {
            product2[k] = arr2[i];
            k++;
            product2[k] = arr1[j];
            if (j == (n1 - 1) && i == (n2 - 1)) {
                cout << "<" << product2[k - 1] << "," << product2[k] << "> ";
            }
            else {
                cout << "<" << product2[k - 1] << "," << product2[k] << ">, ";
            }
        }
    }
    cout << "}";
    cout << "\n";
    //Операция дополнение
    int universe[50]{};
    int sum = 1;
    for (int i = 0; i < 50; i++) {
        universe[i] = sum;
        sum++;
    }
    cout << "\n";
    //Седьмое множество
    int sizec1 = 50 - n1;
    int* complement1 = new int[sizec1];
    int cross2 = 0;
    if (n1 == 50) {
        cout << "Результа операции дополнения 1-го множества: Пустое множество";
    }
    else {
        cout << "Результа операции дополнения 1-го множества: { ";
        for (int i = 0, f = -1; i < 50; i++) {
            for (int j = 0; j <= n1 - 1; j++) {
                if (universe[i] == arr1[j]) {
                    cross2++;
                }
            }
            if (cross2 == 0) {
                f++;
                complement1[f] = universe[i];
                cout << complement1[f] << " ";
            }
            cross2 = 0;
        }
        cout << "}";
    }
    cout << "\n";
    cout << "\n";
    //Восьмое множество
    int sizec2 = 50 - n2;
    int* complement2 = new int[sizec2];
    cross2 = 0;
    if (n2 == 50) {
        cout << "Результа операции дополнения 2-го множества: Пустое множество";
    }
    else {
        cout << "Результа операции дополнения 2-го множества: { ";
        for (int i = 0, f = -1; i < 50; i++) {
            for (int j = 0; j <= n2 - 1; j++) {
                if (universe[i] == arr2[j]) {
                    cross2++;
                }
            }
            if (cross2 == 0) {
                f++;
                complement2[f] = universe[i];
                cout << complement2[f] << " ";
            }
            cross2 = 0;
        }
        cout << "}";
    }
    cout << "\n";
    cout << "\n";
    //Операция разность между 1-ым множеством и 2-ым множества
    //Задаём девятое множество
    cross2 = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                cross2++;
            }
        }
    }
    int sized12 = 0;
    bool ping = false;
    if (cross2 == 0) {
        sized12 = n1;
        ping = true;
    }
    else if (cross2 > 0 && n1 > n2) {
        sized12 = n1 - cross2;
        ping = true;
    }
    else if (cross2 == n1) {
        cout << "Результат разности между 1-ым множеством и 2-ым множеством: Пустое множество";
        sized12 = 0;
    }
    else {
        sized12 = n1 - cross2;
        ping = true;
    }
    int* difference12 = new int[sized12];
    if (ping == true) {
        cout << "Результат разности между 1-ым множеством и 2-ым множеством: { ";
        for (int i = 0, f = -1; i <= (n1 - 1); i++) {
            for (int j = 0; j <= (n2 - 1); j++) {
                if (arr1[i] == arr2[j])
                {
                    break;
                }
                if (j == (n2 - 1)) {
                    f++;
                    difference12[f] = arr1[i];
                    cout << difference12[f] << " ";
                }
            }
        }
        cout << "}";
    }
    cout << "\n";
    cout << "\n";
    //Операция разность между 2-ым множеством и 1-ым множеством
    //Задаём десятое 
    int sized21 = 0;
    ping = false;
    if (cross2 == 0) {
        sized21 = n2;
        ping = true;
    }
    else if (cross2 > 0 && n2 > n1) {
        sized21 = n2 - cross2;
        ping = true;
    }
    else if (cross2 == n2) {
        cout << "Результат разности между 2-ым множеством и 1-ым множеством: Пустое множество";
        sized21 = 0;
    }
    else {
        sized21 = n2 - cross2;
        ping = true;
    }
    int* difference21 = new int[sized21];
    if (ping == true) {
        cout << "Результат разности между 2-ым множеством и 1-ым множеством: { ";
        for (int i = 0, f = -1; i <= (n2 - 1); i++) {
            for (int j = 0; j <= (n1 - 1); j++) {
                if (arr2[i] == arr1[j]) {
                    break;
                }
                if (j == (n1 - 1)) {
                    f++;
                    difference21[f] = arr2[i];
                    cout << difference21[f] << " ";
                }
            }
        }
        cout << "}";
    }
    cout << "\n";
    cout << '\n';
    //Операция симметрическая разность двух множеств
    int sizesym12 = sized12 + sized21;
    int* differencesym12 = new int[sizesym12];
    if (sized12 > 0 && sized21 > 0) {
        limit = 0;
        cout << "Результат операции симметрическая разность: { ";
        for (int f = 0; f <= (sizesym12 - 1); f++) {
            if (f <= (sized12 - 1)) {
                differencesym12[f] = difference12[f];
                cout << differencesym12[f] << " ";
            }
            else {
                differencesym12[f] = difference21[limit];
                cout << differencesym12[f] << " ";
                limit++;
            }
        }
        cout << "}";
    }
    else if (sized12 == 0 && sized21 > 0) {
        cout << "Результат операции симметрическая разность: { ";
        for (int f = 0; f <= (sized21 - 1); f++) {
            differencesym12[f] = difference21[f];
            cout << differencesym12[f] << " ";
        }
        cout << "}";
    }
    else if (sized12 > 0 && sized21 == 0) {
        cout << "Результат операции симметрическая разность: { ";
        for (int f = 0; f <= (sized12 - 1); f++) {
            differencesym12[f] = difference12[f];
            cout << differencesym12[f] << " ";
        }
        cout << "}";
    }
    else {
        cout << "Результат операции симметрическая разность: Пустое множество";
    }
    cout << "\n";
    delete[] arr1;
    delete[] arr2;
    delete[] unit;
    delete[] crossing;
    delete[] product1;
    delete[] product2;
    delete[] complement1;
    delete[] complement2;
    delete[] difference12;
    delete[] difference21;
    delete[] differencesym12;
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    return 0;
}