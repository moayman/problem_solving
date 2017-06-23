#include <iostream>
#include <cstring>
using namespace std;

int coin[120], dp[120][25100];

int MAX(const int &a, const int &b)
{
	if (a > b)
		return a;
	return b;
}

int knapsack(int n, int w)
{
	for (size_t i = 0; i <= w; i++)
	{
		dp[0][i] = 0;
	}

	for (size_t i = 1; i <= n; i++)
	{
		for (int limit = 0; limit <= w; limit++)
		{
			if (coin[i] <= limit)
				dp[i][limit] = MAX(dp[i - 1][limit], dp[i - 1][limit - coin[i]] + coin[i]);
			else
				dp[i][limit] = dp[i - 1][limit];
		}
	}
	return dp[n][w];
}

int main()
{
	int testCase, n;
	cin >> testCase;
	for (size_t a = 0; a < testCase; a++)
	{
		cin >> n;
		int sum = 0;
		for (size_t i = 1; i <= n; i++)
		{
			cin >> coin[i];
			sum += coin[i];
		}
		cout << sum - (knapsack(n, sum / 2) * 2) << endl;
	}
	return 0;
}
