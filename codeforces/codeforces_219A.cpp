#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	int k;
	string s;
	char input;
	cin >> k;
	if (k == 1)
	{
		cin >> s;
		cout << s;
	}
	else
	{
		unordered_map<char, int> data;
		string output;
		while (cin >> input)
		{
			s += input;
			data[input]++;
		}
		for (auto it = data.begin(); it != data.end(); it++)
		{
			if (it->second < k)
			{
				cout << -1;
				return 0;
			}
			else if (it->second % k == 0)
			{
				for (size_t i = 0; i < it->second / k; i++)
				{
					output += it->first;
				}
			}
			else
			{
				cout << -1;
				return 0;
			}
		}
		for (size_t i = 0; i < k; i++)
		{
			cout << output;
		}
	}
	return 0;
}