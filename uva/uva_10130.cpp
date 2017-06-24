#include <iostream>
using namespace std;

int price[1001], weight[1001], personWeight[100], dp[1001][1001 * 30];

int MAX(const int &a, const int &b)
{
	if (a > b)
		return a;
	return b;
}

int knapsack(int n, int W)
{
	for (size_t i = 0; i <= W; i++)
	{
		dp[0][i] = 0;
	}

	for (size_t i = 1; i <= n; i++)
	{
		for (int w = 0; w <= W; w++)
		{
			if (weight[i] <= w)
				dp[i][w] = MAX(dp[i - 1][w], dp[i - 1][w - weight[i]] + price[i]);
			else
				dp[i][w] = dp[i - 1][w];
		}
	}
	return dp[n][W];
}

int main()
{
	int testCases, n, g, w;
	cin >> testCases;
	for (size_t a = 0; a < testCases; a++)
	{
		cin >> n;
		int answer = 0;
		for (size_t i = 1; i <= n; i++)
			cin >> price[i] >> weight[i];
		cin >> g;
		for (size_t i = 0; i < g; i++)
		{
			cin >> w;
			answer += knapsack(n, w);
		}
		cout << answer << endl;
	}
	return 0;
}
