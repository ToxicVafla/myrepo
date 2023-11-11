# **Расчётная работа №1**

Вариант **4.1**, способ выражения графа: **Матрица Инидентности**.

**Постановка задачи:** Найти декартово произведение двух неориентированных графов.

## **Определения**

- Граф — это топологичекая модель, которая состоит из множества вершин и множества соединяющих их рёбер.

- Вершина - точка в графе(V).

- Ребро - неупорядоченная пара двух вершин, которые связаны друг с другом(E).

- Инцидентность - вершина и ребро называются инцидентными, если вершина является для этого ребра концевой.

- Смежность вершин - две вершины называются смежными, если они инцидентны одному ребру.

- Неориентированный граф - граф, в котором рёбра не имеют направления.

- Матрица инцидентности - способ выражения графа, для хранения которого использвуется двумерная матрица размера [V, E], в каждом столбце которой записано одно ребро таким образом: напротив вершин, инцидентных этому ребру, записаны 1, в остальных случаях 0.

- Декартово произведение или прямое произведение G × H графов G и H - это граф, такой, что
  1) множество вершин графа G × H — это прямое произведение V(G) × V(H).
  2) любые две вершины (u,u') и (v,v') смежны в G × H тогда и только тогда, когда

        a) либо u=v и u' смежна v' в H.
    
        b) либо u' =v' и u смежна v в G.

## **Описание алгоритма**

Пользователь вводит путь к двум файлам, содержашим два разных графа, записанных в виде матриц инцидентности. Далее граф считвыается из матрицы инцидентности. Затем по определению декартова произведения двух графов разделим задачу на подзадачи : 1) Нахождение множества вершин графа декартова произведения путём декартова произведения вершин двух исходных графов. 2) Выяснение смежности получившихся вершин, следуя условиям из определения декартова произведения двух графов. Получившийся результат представляем как матрицу инцидентности и выводим результат на экран. Предлагаем пользователю повторить операцию сначала, с другмии входными данными(если пользователь соглашается, алгоритм повторяется).

## **Пример работы**

В каждом тесте будет продемонстрировано три изображения : два изображения исходных графов и результат-вывод в консоли.

- TEST 1

![1](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/1.png)

![2](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/2.png)

![1-2](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/1-2.png)

Граф декартова произведения:

![test1res](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/test1res.png)

- TEST 2

![3](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/3.png)

![4](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/4.png)

![3-4.1](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/3-4.1.png)

![3-4.2](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/3-4.2.png)

Граф декартова произведения:

![test2res](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/test2res.png)

- TEST 3

![5](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/5.png)

![6](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/6.png)

![5-6](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/5-6.png)

Граф декартова произведения:

![test3res](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/test3res.png)

В тесте три, несмотря на то, что в первом графе этого теста нет ребра, соединяющего вершины, результат всё равно есть, единственное, что изменилось при таком тесте, так это то, что при выполнении условия смежности вершин графа декартова произведения, условие b(в определении декартова произведения) не выполнялось

- TEST 4

Полупрозрачные рёбра сделал для того, чтобы сделать тест с графом без рёбер. А так как у меня граф представлен в виде матрицы инцидентности, где за столбики матрицы отвечают рёбра, надо чтобы рёбра были. Поэтому я обозначил полупрозрачными линиями "пустые" рёбра, которых на самом деле нет.

![7](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/7.png)

![8](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/8.png)

![7-8](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/7-8.png)

В результате выполнения программы на экране видим, что количество рёбер равно нулю.

Граф декартова произведения:

![test4res](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/test4res.png)

- TEST 5

Для теста номер пять я использовал такие рёбра, чтобы сделать тест с минимальным количеством вершин, а так как у меня по условию матрица инцидентности, в графе обязаны быть какие-то рёбра.

![9](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/9.png)

![10](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/10.png)

![9-10](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/9-10.png)

Граф декартова произведения:

![test5res](https://github.com/iit-22170x/RPIIS/blob/%D0%9A%D1%80%D1%8E%D0%BA_%D0%92_%D0%92/sem1/RR/code/Pictures%20of%20graphs%20and%20result%20in%20console/test5res.png)

## **Вывод**

В ходе выполнения данной расчётной работы, я приобрёл базовые знания теории графов, на практике выяснил преимущества векторов перед динамическими массивами, усовершенствовал свои навыки работы с функциями, файлами и строками в C++

## **Источники**

https://habr.com/ru/company/otus/blog/568026/

https://habr.com/ru/company/otus/blog/675730/

https://ru.wikipedia.org/wiki/%D0%9F%D1%80%D1%8F%D0%BC%D0%BE%D0%B5_%D0%BF%D1%80%D0%BE%D0%B8%D0%B7%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5_%D0%B3%D1%80%D0%B0%D1%84%D0%BE%D0%B2