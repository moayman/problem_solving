#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
	int n, a, b;
	map<int, int> bottleCount, identical;
	set<int> opener;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a != b)
			opener.insert(b);
		else
			identical[a]++;
		bottleCount[a]++;
	}
	for (auto it = opener.begin(); it != opener.end(); it++)
	{
		if (bottleCount.find(*it) != bottleCount.end())
			n -= bottleCount[*it];
	}
	for (auto it = identical.begin(); it != identical.end(); it++)
	{
		if (opener.find(it->first) == opener.end())
		{
			if (it->second > 1)
			{
				n -= bottleCount[it->first];
			}
			else
			{
				n -= bottleCount[it->first];
				n++;
			}
		}
	}
	cout << n;
	return 0;
}