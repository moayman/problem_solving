#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 0 1 knapsack

int t, n, k;
int r[101], dp[101][1001];

int solve(int index = 0, int currentK = k)
{
	if (index == n)
		return 0;
	if (dp[index][currentK] != -1)
		return dp[index][currentK];
	dp[index][currentK] = 0;
	if (currentK >= r[index])
		dp[index][currentK] = r[index] + solve(index + 1, currentK - r[index]);
	dp[index][currentK] = max(dp[index][currentK], solve(index + 1, currentK));
	return dp[index][currentK];
}

int main()
{
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		cin >> n >> k;
		int R, input;
		for (size_t j = 0; j < n; j++)
		{
			cin >> R;
			r[j] = 0;
			for (size_t k = 0; k < R; k++)
			{
				cin >> input;
				r[j] += input;
			}
		}
		memset(dp, -1, sizeof dp);
		cout << solve() << endl;
	}
	return 0;
}