#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MOD 1000000007
#define NMOD -1000000007

inline long long fastermod(long long a)
{
	if (a == 0)
		return a;
	if (a < 0)
	{
		if (a == NMOD)
			return 0;
		if (a < NMOD)
			return (a % NMOD) + MOD;
		if (a > NMOD)
			return a + MOD;
	}
	// a is positive
	if (a == MOD)
		return 0;
	if (a > MOD)
		return a % MOD;
	return a;
}

int main()
{
	set<pair<pair<long long, long long>, long long> > dp;
	vector<long long> data;
	long long x, y, n, current, prev;
	cin >> x >> y >> n;
	if (n == 1)
		cout << fastermod(x);
	else if (n == 2)
		cout << fastermod(y);
	else
	{
		n -= 2;
		x = fastermod(x);
		y = fastermod(y);
		current = y;
		prev = x;
		data.push_back(prev);
		data.push_back(current);
		size_t rep = -1;
		for (size_t i = 0; i < n; i++)
		{
			x = prev; // temp;
			y = current; // temp;
			if (current == 0 && prev == 0)
			{
				cout << 0;
				return 0;
			}
			current = fastermod(current - prev);
			prev = y;
			if (dp.find(pair<pair<long long, long long>, long long>(pair<long long, long long>(x, y), current)) != dp.end())
			{
				rep = i;
				break;
			}
			else
			{
				dp.insert(pair<pair<long long, long long>, long long>(pair<long long, long long>(x, y), current));
				data.push_back(current);
			}
		}
		if (rep != -1)
			cout << data[(n + 1) % rep];
		else
			cout << fastermod(current);
	}
	return 0;
}
