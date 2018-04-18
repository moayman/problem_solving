#include <iostream>
#include <cstring>
using namespace std;

long long c = 0;
long long values[] = { 1, 5, 10, 25, 50 };
long long coinChanges[7500][5];

long long coinChange(long long cents = c, long long currentCoin = 0)
{
	if (cents == 0)
		return 1;
	if (coinChanges[cents][currentCoin] != -1)
		return coinChanges[cents][currentCoin];
	coinChanges[cents][currentCoin] = 0;
	for (size_t i = currentCoin; i < 5; i++)
		if (cents >= values[i])
			coinChanges[cents][currentCoin] += coinChange(cents - values[i], i);
	return coinChanges[cents][currentCoin];
}

int main()
{
	memset(coinChanges, -1, sizeof coinChanges);
	while (cin >> c)
		cout << coinChange() << endl;
	return 0;
}
