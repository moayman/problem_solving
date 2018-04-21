#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

long long n, m, k, data[20], c[20][20], dp[20][300000];

long long solve(long long numberOfDishes, long long currentIndex, long long mask)
{
	if (numberOfDishes == m)
		return 0;
	if (dp[currentIndex][mask] != -1)
		return dp[currentIndex][mask];
	for (size_t i = 0; i < n; i++)
	{
		if ((mask & (1 << i)) == 0)
			dp[currentIndex][mask] = max(dp[currentIndex][mask], solve(numberOfDishes + 1, i, mask | (1 << i)) + data[i] + (mask ? c[currentIndex][i] : 0));
	}
	return dp[currentIndex][mask];
}

int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> k;
	for (size_t i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	long long i, j;
	for (size_t a = 0; a < k; a++)
	{
		cin >> i >> j;
		cin >> c[i - 1][j - 1];
	}
	cout << solve(0, 0, 0);
	return 0;
}
