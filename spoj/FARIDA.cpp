#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// BOTTOM UP https://www.quora.com/Is-there-any-solution-of-Princess-Farida-problem-using-bottoms-up-approach

int N;
long long monsterCoins[10001];
long long dp[10001];

int main()
{
	int t;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		memset(dp, 0, sizeof dp);
		cin >> N;
		for (size_t j = 1; j < N + 1; j++)
		{
			cin >> monsterCoins[j];
		}
		dp[1] = monsterCoins[1];
		for (size_t j = 2; j < N + 1; j++)
		{
			dp[j] = max(monsterCoins[j] + dp[j - 2], dp[j - 1]);
		}
		cout << "Case " << i + 1 << ": " << dp[N] << endl;
	}
	return 0;
}

//=================================================================================

// TOP DOWN
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n;
long long dp[10000], coins[10000];

long long farida(int currentIndex = 0)
{
	if (currentIndex >= n)
		return 0;
	if (dp[currentIndex] != -1)
		return dp[currentIndex];
	return dp[currentIndex] = max(farida(currentIndex + 2) + coins[currentIndex], farida(currentIndex + 1));
}

int main()
{
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		memset(dp, -1, sizeof dp);
		cin >> n;
		for (size_t j = 0; j < n; j++)
		{
			cin >> coins[j];
		}
		cout << "Case " << i + 1 << ": " << farida() << endl;
	}
	return 0;
}
