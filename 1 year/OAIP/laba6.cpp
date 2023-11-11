#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char str1[256];
	cout << "Enter str" << endl;
	cin.getline(str1, 256);
	int len = strlen(str1);
	int max_len = 0;						// max length of a word
	int wordlencounter = 0;
	int maxpos = 0;
	int wordsamount = 1;
	int pos_of_maxword = 0;
	int iforwhile = 0;
	if (str1[0] == '\0')
	{
		cout << "str is empty";
		return 0;
	}
	while (str1[iforwhile] == ' ')
	{
		if (str1[iforwhile + 1] == '\0')
		{
			cout << "There is no words in str";
			return 0;
		}
		iforwhile++;
	}
	for (int i = 0; i <= len; i++)
	{
		if (wordlencounter >= max_len)		// searching for the last(if there are more than one word with the same number of symbols) word with max length
		{
			max_len = wordlencounter;
			pos_of_maxword = wordsamount;
			maxpos = i - max_len + 1;		// doing +1 because of char class starting with 0
		}
		wordlencounter++;
		if (str1[i] == ' ')
		{
			wordlencounter = 0;
			if (str1[i + 1] != ' ' && str1[i + 1] != '\0' && max_len != 0)	// if the next symbol after space isn't space and the end of str
			{																// and also i use max_len != 0 for prevent counting spaces as word on the first position of the str
				wordsamount++;
			}
		}
	}
	cout << "-------------------------------------------------------------------\n" << endl;
	cout << pos_of_maxword << " - nubmer of a word with max length(TASK)" << endl;
	cout << maxpos << " - position of the first symbol in the word with max length(TASK)\n" << endl;	
	cout << "-------------------------------------------------------------------\n" << endl;
	cout << max_len << " - max length of the word in str(OPTIONAL)" << endl;
	cout << wordsamount << " - an amount of words in str(OPTIONAL)\n" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	for (int i = 0; i < strlen(str1); i++) {
		cout << str1[i];
	}
}