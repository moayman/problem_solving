#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, numbers[11];
int dp[11][11];

int LIS(int i = 0, int prev = n){
	if (i == n)
		return dp[i][prev] = 0;
	if (dp[i][prev] != -1)
		return dp[i][prev];
	return dp[i][prev] = max(LIS(i + 1, prev), (numbers[i]>numbers[prev] ? LIS(i + 1, i) + 1 : 0));
}

int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	cout << LIS();
	return 0;
}
