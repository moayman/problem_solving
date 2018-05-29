#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int n = s1.length(), m = s2.length();
	map<char, int> data;
	for (size_t i = 0; i < n; i++)
	{
		if (s1[i] != ' ')
			data[s1[i]]++;
	}
	for (size_t i = 0; i < m; i++)
	{
		if (s2[i] != ' ')
		{
			if (data.find(s2[i]) != data.end() && data[s2[i]] > 0)
				data[s2[i]]--;
			else
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}