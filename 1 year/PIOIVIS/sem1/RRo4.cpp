#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> record_of_MI(int* strnum, int* boldnum, string path)		//запись матрицы инцидентности из файла
{
	vector<string> matrix;
	string str;
	string vec;
	ifstream file(path);
	getline(file, str);

	int c_for_bold_num = 0;
	do
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (i % 2 == 0)
			{
				cout << str[i];
				vec += str[i];
				matrix.push_back(vec);
				vec.clear();
			}
			else
			{
				cout << " ";
			}

		}
		cout << endl;
		str.clear();
		getline(file, str);
		c_for_bold_num++;
	} while (str[0] != '\0');

	*boldnum = matrix.size() / c_for_bold_num;
	*strnum = matrix.size() / *boldnum;
	file.close();
	return matrix;
}

vector<string> direct_product_of_verteceis(int strnum1, int strnum2, vector<string> matrix1, vector<string> matrix2, int* vertices)	//
{
	string vec;
	vector<string> directv;
	cout << "Set of vertices of the direct product of 2 graphs :\n" << "{ ";		//множество вершин декатрова произведения двух графов
	int k = 0;																	//каждая <n,m> - одна вершина
	for (int i = 1; i <= strnum1; i++)
	{
		for (int j = 1; j <= strnum2; j++, k++)
		{
			vec += to_string(i);
			directv.push_back(vec);
			vec.clear();
			k++;
			vec += to_string(j);
			directv.push_back(vec);
			vec.clear();
			if (j == strnum2 && i == strnum1)
			{
				cout << "<" << directv[k - 1] << "," << directv[k] << "> ";
			}
			else
			{
				cout << "<" << directv[k - 1] << "," << directv[k] << ">, ";
			}
		}
	}
	cout << "}" << endl;

	*vertices = directv.size() / 2;

	cout << '\n' << *vertices << " - number of vertices\n" << endl;

	return directv;
}


void edjes_and_result(vector<string> directv, int vertices, vector<string> matrix1, vector<string> matrix2, int boldnum1, int boldnum2)	//проверяет условия смежности вершин нового графа
{																																			//и выводит результат(МИ декартового произв)
	string edjes;
	
	int counter = 1;
	int a = 0;
	int strnum1 = 0;
	int strnum2 = 0;
	int counter_for_edjes = 0;
	for (int i = 0; i < (vertices-1) * 2; i++)
	{
		if (i % 2 == 0)
		{
			while (counter != vertices - (i/2))
			{
				if (directv[i] == directv[i + 2 * counter])
				{
					a = i + 1;
					strnum1 = stoi(directv[a])-1;
					strnum2 = stoi(directv[a + 2 * counter])-1;
					
					for (int k = 0; k < boldnum2; k++)
					{
						if ((matrix2[k + strnum1 * boldnum2] == matrix2[k + strnum2 * boldnum2]) && (matrix2[k + strnum1 * boldnum2] == "1"))
						{
							cout << "vertex " << a/2+1 << " and vertex " << (a + 2 * counter)/2+1 << " are linked\n" << endl;
							edjes += to_string(a / 2);
							edjes += to_string((a + 2 * counter) / 2);
							counter_for_edjes++;
							break;
						}
					}
				}
				counter++;
			}
			counter = 1;
		}
		else
		{
			while (counter != vertices - (i / 2) - 1)
			{
				if (directv[i] == directv[i + 2 * counter])
				{
					a = i + 1;
					strnum1 = stoi(directv[a]) - 1;
					strnum2 = stoi(directv[a + 2 * counter]) - 1;

					for (int k = 0; k < boldnum1; k++)
					{
						if ((matrix1[k + strnum1 * boldnum1] == matrix1[k + strnum2 * boldnum1]) && (matrix1[k + strnum1 * boldnum1] == "1"))
						{
							cout << "vertex " << a / 2 << " and vertex " << (a + 2 * counter) / 2 << " are connected\n" << endl;
							edjes += to_string(a / 2 - 1);
							edjes += to_string((a + 2 * counter) / 2 - 1);
							counter_for_edjes++;
							break;
						}
					}
				}
				counter++;
			}
			counter = 1;
		}
	}
	
	cout << counter_for_edjes << " - number of edjes in direct product of 2 graphs\n" << endl;
	

	int** array = new int* [vertices];
	for (int i = 0; i < vertices; i++)
	{
		array[i] = new int[counter_for_edjes];
	}


	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < counter_for_edjes; j++)
		{
			array[i][j] = 0;
		}
	}

	
	string x;
	string y;
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < counter_for_edjes*2; j++)
		{
			x += edjes[j];
			if (stoi(x) == i)
			{
				array[i][j/2] = 1;
			}
			x.clear();
		}
	}


	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < counter_for_edjes; j++)
		{
			cout << array[i][j] << "  ";
		}
		cout << '\n';
	}


	for (int i = 0; i < vertices; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}

void tests(string path1, string path2)
{
	int strnum1;
	int boldnum1;
	int strnum2;
	int boldnum2;
	int vertices;
	
	cout << "\nFirst file's insides :" << endl;
	vector<string> matrix1 = record_of_MI(&strnum1, &boldnum1, path1);
	cout << "\nSecond file's insides :" << endl;
	vector<string> matrix2 = record_of_MI(&strnum2, &boldnum2, path2);
	cout << '\n' << endl;

	vector<string> directv = direct_product_of_verteceis(strnum1, strnum2, matrix1, matrix2, &vertices);

	edjes_and_result(directv, vertices, matrix1, matrix2, boldnum1, boldnum2);
}

int main()
{
	string path1;
	string path2;
	string key;

	do
	{
		key.clear();

		cout << "Enter path to the file with 1st graph(matrix of incidence)(for example MyFile1.txt)" << endl;
		cin >> path1;
		cout << "Enter path to the file with 2nd graph(matrix of incidence)(for example MyFile2.txt)" << endl;
		cin >> path2;
		cout << endl;

		tests(path1, path2);

		path1.clear();
		path2.clear();

		cout << "Wanna do one more operation?\n" << "Enter \"y\" (yes) or smth else to end" << endl;
		cin >> key;
	} while (key == "y");
}