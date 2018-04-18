#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f

int t, n, m;
string s1, s2;
int dp[3000][3000][2][2];

int solve(int i = 0, int j = 0, bool swap1 = false, bool swap2 = false)
{
	if (i == n)
		return m - j; // return left out characters
	if (j == m)
		return n - i; // return left out characters
	if (dp[i][j][swap1][swap2] != INF)
		return dp[i][j][swap1][swap2];
	if (s1[i - swap1] == s2[j - swap2])
		dp[i][j][swap1][swap2] = solve(i + 1, j + 1, false, false); // match
	else
	{
		dp[i][j][swap1][swap2] = min(dp[i][j][swap1][swap2], solve(i + 1, j, false, swap2) + 1); // insert
		dp[i][j][swap1][swap2] = min(dp[i][j][swap1][swap2], solve(i, j + 1, swap1, false) + 1); // delete
		dp[i][j][swap1][swap2] = min(dp[i][j][swap1][swap2], solve(i + 1, j + 1, false, false) + 1); // replace
		if (j != m && s1[i - swap1] == s2[j - swap2 + 1])
			dp[i][j][swap1][swap2] = min(dp[i][j][swap1][swap2], solve(i + 1, j + 1, false, true) + 1); // replace
		if (i != n && s2[j - swap2] == s1[i - swap1 + 1])
			dp[i][j][swap1][swap2] = min(dp[i][j][swap1][swap2], solve(i + 1, j + 1, true, false) + 1); // replace
	}
	return dp[i][j][swap1][swap2];
}

int main()
{
	while (cin >> s1 >> s2)
	{
		if (s1 == "*" && s2 == "*")
			return 0;
		memset(dp, INF, sizeof dp);
		n = s1.length();
		m = s2.length();
		cout << solve() << endl;
	}
	return 0;
}
