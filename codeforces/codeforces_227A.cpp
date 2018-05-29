#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main()
{
	map<long long, set<long long> > data;
	long long input, n, m, answer1 = 0, answer2 = 0;
	cin >> n;
	++n;
	for (size_t i = 1; i < n; i++)
	{
		cin >> input;
		data[input].insert(i);
	}
	cin >> m;
	for (size_t i = 0; i < m; i++)
	{
		cin >> input;
		answer1 += *data[input].begin();
		answer2 += n - *data[input].rbegin();
	}
	cout << answer1 << ' ' << answer2;
	return 0;
}