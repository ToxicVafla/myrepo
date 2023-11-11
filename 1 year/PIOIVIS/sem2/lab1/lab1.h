#pragma once

#include <iostream>
#include <vector>

using namespace std;

class fenwickTree {
private:
	vector<int> FenwickTree;
	vector<int> origArray;
public:
	fenwickTree(vector<int> SourceArray) {
		origArray.assign(SourceArray.begin(), SourceArray.end());
		for (int i = 0, k = 0, sum = 0; i < origArray.size(); i++, sum = 0)
		{
			k = i & (i + 1);

			while (k <= i)
			{
				sum += origArray[k];
				k++;
			}
			
			FenwickTree.push_back(sum);
		}
		cout << "Original array: ";
		printarr(origArray);
		cout << "\nFenwick Tree: ";
		printarr(FenwickTree);
	}

	int getSum(int UpperBound, int LowerBound)	// sum[k..l] = sum[0..k] - sum[0..l-1]
	{
		int SumOfRange = 0;
		LowerBound -= 1;

		for (int i = 0; UpperBound != -1; i++)
		{
			SumOfRange += FenwickTree[UpperBound];
			UpperBound = (UpperBound & (UpperBound + 1)) - 1;
		}

		for (int i = 0; LowerBound != -1; i++)
		{
			SumOfRange -= FenwickTree[LowerBound];
			LowerBound = (LowerBound & (LowerBound + 1)) - 1;
		}

		cout << '\n';
		return SumOfRange;
	}

	void updateFenwickTree(int numOfEl, int newValue)
	{
		int diff = newValue - origArray[numOfEl];
		origArray[numOfEl] = newValue;
		while (numOfEl <= FenwickTree.size())
		{
			FenwickTree[numOfEl] += diff;
			numOfEl = numOfEl | (numOfEl + 1);
		}
		cout << "Updated original array: ";
		printarr(origArray);
		cout << "\nUpdated Fenwick Tree: ";
		printarr(FenwickTree);
		cout << '\n';
	}

	void printarr(vector<int> vector)
	{
		for (int i = 0; i < vector.size(); i++)
		{
			cout << vector[i] << " ";
		}
	}
};

int test(vector<int> Array)
{
	fenwickTree test(Array);

	int key = 0;
	while (key == 0)
	{
		int switcher = 0;
		cout << "\nChoose operation:\n- 1 for get sum in range [k..l]\n- 2 for update element\n- something else for end\n";
		cin >> switcher;

		int upperBound = 0, lowerBound = 0;
		int numOfCell = 0, value = 0;

		switch (switcher)
		{
		case 1:
			cout << "Input 1)lower bound and 2)upper bound for your range\n";
			cin >> lowerBound >> upperBound;
			cout << "Sum in range [" << lowerBound << ".." << upperBound << "] : " << test.getSum(upperBound, lowerBound);
			cout << '\n';
			break;
		case 2:

			cout << "\nInput 1)number of cell you wanna change and its 2)value\n";
			cin >> numOfCell >> value;
			test.updateFenwickTree(numOfCell, value);
			break;
		default:
			return 0;
		}
	}

}