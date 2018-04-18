#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, s;
long long dp[70][70][2];


long long solve(int currentIndex = 0, int locked = 0, bool prevLocked = false)
{
	if (currentIndex == n)
		return locked == s;
	if (dp[currentIndex][locked][prevLocked] != -1)
		return dp[currentIndex][locked][prevLocked];
	return dp[currentIndex][locked][prevLocked] =
		solve(currentIndex + 1, currentIndex == 0 ? locked : (prevLocked ? locked - 1 : locked), false) + // left unlocked
		solve(currentIndex + 1, locked + 1, true); // locked
}

int main()
{
	while (cin >> n >> s)
	{
		if (n < 0 || s < 0)
			return 0;
		memset(dp, -1, sizeof dp);
		cout << solve() << endl;
	}
	return 0;
}
