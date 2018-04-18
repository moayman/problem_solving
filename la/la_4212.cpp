#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// BOTTOM UP

int m, n;
long long rowResult[100001], currentSet[100001], dp[100001];

int main()
{
	while (cin >> m >> n)
	{
		if (m == 0 && n == 0)
			break;
		for (size_t i = 1; i < m + 1; i++)
		{
			for (size_t j = 1; j < n + 1; j++)
			{
				cin >> currentSet[j];
			}
			dp[1] = currentSet[1];
			for (size_t j = 2; j < n + 1; j++)
			{
				dp[j] = max(currentSet[j] + dp[j - 2], dp[j - 1]);
			}
			rowResult[i] = dp[n];
		}
		dp[1] = rowResult[1];
		for (size_t j = 2; j < m + 1; j++)
		{
			dp[j] = max(rowResult[j] + dp[j - 2], dp[j - 1]);
		}
		cout << dp[m] << endl;
	}
	return 0;
}

//==================================================================

// TOP DOWN TLE :(

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int m, n;
int *currentDimension = &n;
long long rowResult[100000], currentSet[100000], dp[100000];
long long* toSolve = currentSet;

long long solve(int currentIndex = 0)
{
	if (currentIndex >= *currentDimension)
		return 0;
	if (dp[currentIndex] != -1)
		return dp[currentIndex];
	return dp[currentIndex] = max(solve(currentIndex + 2) + toSolve[currentIndex], solve(currentIndex + 1));
}

int main()
{
	while (cin >> m >> n)
	{
		if (m == 0 && n == 0)
			break;
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				cin >> currentSet[j];
			}
			memset(dp, -1, sizeof dp);
			rowResult[i] = solve();
		}
		memset(dp, -1, sizeof dp);
		toSolve = rowResult;
		currentDimension = &m;
		cout << solve() << endl;
		toSolve = currentSet;
		currentDimension = &n;
	}
	return 0;
}
