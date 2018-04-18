#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f

long long dp[5001][10000], n, H[5000];

long long solve(int i = 0, long long lastH = 0)
{
	if (i == n)
		return 0;
	if (dp[i][lastH] != INF)
		return dp[i][lastH];
	if (H[i] <= lastH)
		dp[i][lastH] = min(dp[i][lastH], solve(i + 1, min(H[i], 5001LL)));
	else
	{
		dp[i][lastH] = min(dp[i][lastH], solve(i + 1, min(H[i], 5001LL)) + H[i] - lastH);
		dp[i][lastH] = min(dp[i][lastH], solve(i + 1, lastH) + 1);
	}
	return dp[i][lastH];
}


int main()
{
	memset(dp, INF, sizeof dp);
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> H[i];
	}
	cout << solve();
	return 0;
}
