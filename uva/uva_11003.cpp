#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int t, w[1100], l[1100];
int dp[1100][3100];

int solve(int currentIndex, int rem)
{
	if (currentIndex == t)
		return 0;
	if (dp[currentIndex][rem] != -1)
		return dp[currentIndex][rem];
	dp[currentIndex][rem] = solve(currentIndex + 1, rem);
	if (rem >= w[currentIndex + 1])
		dp[currentIndex][rem] = max(dp[currentIndex][rem], solve(currentIndex + 1, min(rem - w[currentIndex + 1], l[currentIndex + 1])) + 1);
	return dp[currentIndex][rem];
}

int main()
{
	while (cin >> t)
	{
		if (t == 0)
			return 0;
		memset(dp, -1, sizeof dp);
		for (size_t i = 0; i < t; i++)
		{
			cin >> w[i] >> l[i];
		}
		w[t] = l[t] = 0;
		int solution = 0;
		for (size_t i = 0; i < t; i++)
		{
			solution = max(solution, solve(i, l[i]));
		}
		cout << solution << endl;
	}
	return 0;
}
