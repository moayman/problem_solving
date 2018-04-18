#include <iostream>
#include <cstring>
#include <string>
using namespace std;

long long values[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
long long dollars[30001][11];

long long Dollars(long long cents, long long currentCoin = 0)
{
	if (cents == 0)
		return 1;
	if (dollars[cents][currentCoin] != -1)
		return dollars[cents][currentCoin];
	dollars[cents][currentCoin] = 0;
	for (size_t i = currentCoin; i < 11; i++)
	if (cents >= values[i])
		dollars[cents][currentCoin] += Dollars(cents - values[i], i);
	return dollars[cents][currentCoin];
}

int main()
{
	// issue when inputting as a double 18.90 = 18.899999999999
	string input;
	long long inupper, inlower;
	memset(dollars, -1, sizeof dollars);
	while (cin >> input)
	{
		if (input != "0.00") {
			sscanf(input.c_str(), "%lld.%lld", &inupper, &inlower);
			printf("%6s%17lld\n", input.c_str(), Dollars((inupper * 100) + inlower));
		}
	}
	return 0;
}
