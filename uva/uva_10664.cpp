#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;

int weights[30], dp[30][500];

int MAX(const int &a, const int &b)
{
	if (a > b)
		return a;
	return b;
}

int knapsack(int n, int w)
{
	memset(dp, 0, sizeof dp);

	for (size_t i = 1; i <= n; i++)
	{
		for (int limit = 0; limit <= w; limit++)
		{
			if (weights[i] <= limit)
				dp[i][limit] = MAX(dp[i - 1][limit], dp[i - 1][limit - weights[i]] + weights[i]);
			else
				dp[i][limit] = dp[i - 1][limit];
		}
	}
	return dp[n][w];
}

int main()
{
	int m, n;
	cin >> m;
	cin.ignore();
	for (size_t a = 0; a < m; a++)
	{
		memset(weights, 0, sizeof weights);
		int sum = 0, n = 0;
		string s;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> weights[n])
		{
			sum += weights[n];
			++n;
		}
		if (sum % 2 == 0 && knapsack(n, sum / 2) * 2 == sum)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
