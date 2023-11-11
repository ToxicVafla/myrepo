#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

vector<string> Symm_diff(vector<string> elements)
{
	vector<string> result;
	int counter;
	for (int i = 0; i < elements.size(); i++)
	{
		counter = 0;
		for (int j = 0; j < elements.size(); j++)
		{
			if (i == j)continue;
			if (elements[i] == elements[j])
			{
				counter++;
			}
		}
		if (counter == 0)
		{
			result.push_back(elements[i]);
		}
	}

	return result;
}
void Def_Sort_subsets(string& unsorted_subset)
{

	// check for empty set
	if (unsorted_subset == "{}")
	{
		unsorted_subset = "{}";
		return;
	}

	// pulling set's content
	string subsetContent = unsorted_subset.substr(1, unsorted_subset.size() - 2);

	vector<string> subsetElements;
	size_t pos = 0;
	string delimiter = ",";
	while ((pos = subsetContent.find(delimiter)) != string::npos)
	{
		string element = subsetContent.substr(0, pos);
		subsetElements.push_back(element);
		subsetContent.erase(0, pos + delimiter.length());
	}
	subsetElements.push_back(subsetContent);

	// sorting elements
	sort(subsetElements.begin(), subsetElements.end());

	// forms unsorted subset
	string sortedSubset = "{";
	for (int j = 0; j < subsetElements.size(); j++)
	{
		sortedSubset += subsetElements[j];
		if (j < subsetElements.size() - 1)
		{
			sortedSubset += ",";
		}
	}
	unsorted_subset = sortedSubset;
}

vector<string> Output(string path)
{
	fstream file;
	file.open(path, fstream::in);
	vector<string> elements;

	string line;
	string unsorted_subset;
	int bracket_counter = 0;
	while (getline(file, line))
	{
		if (line.size() == 0)
		{
			continue;
		}
		string raw_el;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == '{')
			{
				while (line[i] != '}')	//пока будет работать только для подмножеств стандартной глубины, те без подмножеств в подмножествах
				{
					raw_el += line[i];
					i++;
				}
				raw_el += line[i];
				Def_Sort_subsets(raw_el);

			}
			if (line[i] == '<')
			{
				bracket_counter++;
				while (bracket_counter != 0)
				{
					if (line[i] == '<' && raw_el.size() != 0)bracket_counter++;
					if (line[i] == '>')bracket_counter--;
					raw_el += line[i];
					i++;
				}
			}
			if (line[i] != ',')
			{
				if (raw_el == "{}")
				{
					continue;
				}
				raw_el += line[i];
			}
			else
			{
				elements.push_back(raw_el);
				raw_el.clear();
			}
		}
		elements.push_back(raw_el);
		raw_el.clear();
	}

	file.close();
	return elements;
}

void Test(string link)
{
	vector<string> elements = Output(link);
	vector<string> result = Symm_diff(elements);

	cout << "Result: ";

	if (result.size() == 0)
	{
		cout << "empty set";
	}
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << " ";
		}
	}

	cout << '\n';
}
