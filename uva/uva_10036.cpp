#include <iostream>
#include <cstring>
using namespace std;

int T, N, K;
int numbers[10000];
int dp[10000][100];

//bool divisible(int index = 1, int currentValue = numbers[0])
//{
//	if (index == N)
//		return currentValue % K == 0;
//	return divisible(index + 1, currentValue + numbers[index]) || divisible(index + 1, currentValue - numbers[index]);
//}

bool divisibleDP(int index = 1, int currentValue = numbers[0] % K)
{	// -------------------------------------------------------^^^ so important
	if (index == N)
		return currentValue % K == 0;
	if (dp[index][currentValue] != -1)
		return dp[index][currentValue];
	dp[index][currentValue] = divisibleDP(index + 1, (currentValue + numbers[index]) % K) || divisibleDP(index + 1, (currentValue - numbers[index]) % K);
	return dp[index][currentValue];
}

int main()
{
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		cin >> N >> K;
		memset(dp, -1, sizeof dp);
		for (size_t j = 0; j < N; j++)
		{
			cin >> numbers[j];
		}
		cout << (divisibleDP() ? "Divisible" : "Not divisible") << endl;
	}
	return 0;
}
