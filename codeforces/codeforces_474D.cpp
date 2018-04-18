#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int t, k, a, b, A, B;
long long dp[100001];
long long acc[100001];

long long solve(long long rem)
{
	if (rem == 0)
		return 1;
	if (dp[rem] != -1)
		return dp[rem];
	dp[rem] = 0;
	if (rem >= k)
		dp[rem] += solve(rem - k);
	dp[rem] += solve(rem - 1);
	return dp[rem] = (dp[rem] + 1000000007) % 1000000007;
}

void accumulate()
{
	acc[1] = dp[1];
	for (size_t i = 2; i < 100001; i++)
	{
		acc[i] = acc[i - 1] + dp[i];
	}
}

void main()
{
	cin >> t >> k;
	memset(dp, -1, sizeof dp);
	for (size_t i = 1; i < 100001; i++)
	{
		solve(i);
	}
	accumulate();
	for (size_t i = 0; i < t; i++)
	{
		cin >> a >> b;
		cout << (acc[b] - acc[a - 1]) % 1000000007 << endl;
	}
}
