#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 0 1 knapsack

int t, n, k;
int w[50], v[50];
int dp[51][1001];

int solve(int index = 0, int currentW = k)
{
	if (index == n)
		return 0;
	if (dp[index][currentW] != -1)
		return dp[index][currentW];
	dp[index][currentW] = 0;
	if (currentW >= w[index])
		dp[index][currentW] = v[index] + solve(index + 1, currentW - w[index]);
	dp[index][currentW] = max(dp[index][currentW], solve(index + 1, currentW));
	return dp[index][currentW];
}

int main()
{
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		cin >> k >> n;
		for (size_t j = 0; j < n; j++)
		{
			cin >> w[j] >> v[j];
		}
		memset(dp, -1, sizeof dp);
		cout << "Hey stupid robber, you can get " << solve() << "." << endl;
	}
	return 0;
}