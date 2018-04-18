#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T, M, C, K;
int garmentStyles[20];
int garmentPrices[20][20];

int dp[201][20][20];

int solve(int currentM = 0, int currentIndex = 0, int prevSelection = 0)
{
	if (currentIndex == C)
		return currentM;
	if (dp[currentM][currentIndex][prevSelection] != -1)
		return dp[currentM][currentIndex][prevSelection];
	for (size_t i = 0; i < garmentStyles[currentIndex]; i++)
	{
		if (currentM + garmentPrices[currentIndex][i] <= M)
			dp[currentM][currentIndex][prevSelection] = max(dp[currentM][currentIndex][prevSelection], solve(currentM + garmentPrices[currentIndex][i], currentIndex + 1, i));
	}
	return dp[currentM][currentIndex][prevSelection];
}

int main()
{
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		memset(dp, -1, sizeof dp);
		cin >> M >> C;
		for (size_t j = 0; j < C; j++)
		{
			cin >> garmentStyles[j];
			for (size_t k = 0; k < garmentStyles[j]; k++)
			{
				cin >> garmentPrices[j][k];
			}
			sort(&garmentPrices[j][0], &garmentPrices[j][garmentStyles[j]]);
		}
		solve();
		if (dp[0][0][0] == -1)
			cout << "no solution" << endl;
		else
			cout << dp[0][0][0] << endl;
	}
	return 0;
}
