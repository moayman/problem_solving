#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

int main()
{
	int m, n;
	string word;
	unordered_map<string, unsigned long long> dictionary;
	cin >> m >> n;
	for (size_t i = 0; i < m; i++)
	{
		cin >> word;
		cin >> dictionary[word];
	}
	for (size_t i = 0; i < n; i++)
	{
		unsigned long long hayPoints = 0;
		while (true)
		{
			cin >> word;
			if (word == ".")
				break;
			if (dictionary.find(word) != dictionary.end())
				hayPoints += dictionary[word];
		}
		cout << hayPoints << endl;
	}
	return 0;
}