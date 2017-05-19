#include <iostream>
#include <map>
using namespace std;

void main()
{
	size_t m, n;
	int input;
	long long output = 0;
	cin >> n >> m;
	map <int, unsigned int> data;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		data[input]++;
	}
	for (map<int, unsigned int>::iterator it = data.begin(); it != data.end() && m > 0 && it->first < 0; it++)
	{
		while (it->second > 0 && m > 0)
		{
			output -= it->first;
			it->second--;
			m--;
		}
	}
	cout << output;
}