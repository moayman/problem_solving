#include <iostream>
#include <vector>
#include <string>
using namespace std;

unsigned int dictionarySize, rules, depth, ruleSize;
vector<string> dictionaryWords, currentSolution, intToChar = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
string currentRule;

void passwords(int index)
{
	if (index == ruleSize)
	{
		for (size_t i = 0; i < currentSolution.size(); i++)
			cout << currentSolution[i];
		cout << endl;
		return;
	}
	if (currentRule[index] == '#')
	{
		for (size_t i = 0; i < dictionarySize; i++)
		{
			currentSolution.push_back(dictionaryWords[i]);
			passwords(index + 1);
			currentSolution.pop_back();
		}
	}
	else
	{
		for (size_t i = 0; i < 10; i++)
		{
			currentSolution.push_back(intToChar[i]);
			passwords(index + 1);
			currentSolution.pop_back();
		}
	}
}

int main()
{
	string word;
	while (cin >> dictionarySize)
	{
		cout << "--" << endl;
		dictionaryWords.clear();
		for (size_t i = 0; i < dictionarySize; i++)
		{
			cin >> word;
			dictionaryWords.push_back(word);
		}
		cin >> rules;
		for (size_t i = 0; i < rules; i++)
		{
			currentSolution.clear();
			cin >> currentRule;
			ruleSize = currentRule.size();
			passwords(0);
		}
	}
	return 0;
}