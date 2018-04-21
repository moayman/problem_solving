#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int T, E, F, S, N, P[600], W[600], dp[10100];

// TLE because of memset
int solve(int rem = S)
{
	if (rem == 0)
		return 0;
	if (dp[rem] != INF)
		return dp[rem];
	for (size_t i = 0; i < N; i++)
	{
		if (rem >= W[i])
			dp[rem] = min(dp[rem], solve(rem - W[i]) + P[i]);
	}
	return dp[rem];
}

void solveIter()
{
	dp[0] = 0;
	for (size_t i = 1; i <= S; i++)
	{
		dp[i] = -1;
		for (size_t j = 0; j < N; j++)
		{
			if (i >= W[j] && dp[i - W[j]] != -1 && (dp[i] == -1 || P[j] + dp[i - W[j]] <= dp[i]))
				dp[i] = dp[i - W[j]] + P[j];
		}
	}
}

int main()
{
	//int solution;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		//memset(dp, INF, sizeof dp);
		cin >> E >> F >> N;
		S = F - E;
		for (size_t j = 0; j < N; j++)
		{
			cin >> P[j] >> W[j];
		}
		solveIter();
		if (dp[S] == -1)
			cout << "This is impossible.\n";
		else
			cout << "The minimum amount of money in the piggy-bank is " << dp[S] << ".\n";
		/*solution = solve();
		if (solution == INF)
		cout << "This is impossible.\n";
		else
		cout << "The minimum amount of money in the piggy-bank is " << solution << ".\n";*/
	}
	return 0;
}
