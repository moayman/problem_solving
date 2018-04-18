#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f

int t;
string s1, s2;
int dp[3000][3000];

int solve(int i1 = 0, int i2 = 0)
{
	if (i1 == s1.length())
		return s2.length() - i2; // return left out characters
	if (i2 == s2.length())
		return s1.length() - i1; // return left out characters
	if (dp[i1][i2] != INF)
		return dp[i1][i2];
	if (s1[i1] == s2[i2])
		dp[i1][i2] = solve(i1 + 1, i2 + 1); // match
	else
	{
		dp[i1][i2] = min(dp[i1][i2], solve(i1 + 1, i2) + 1); // insert
		dp[i1][i2] = min(dp[i1][i2], solve(i1, i2 + 1) + 1); // delete
		dp[i1][i2] = min(dp[i1][i2], solve(i1 + 1, i2 + 1) + 1); // replace
	}
	return dp[i1][i2];
}

int main()
{
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		cin >> s1 >> s2;
		memset(dp, INF, sizeof dp);
		cout << solve() << endl;
	}
	return 0;
}
