#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1073741824
long long dp[1000001];

int main()
{
	int a, b, c;
	long long answer = 0;
	cin >> a >> b >> c;
	a++; b++; c++;
	for (long long i = 1; i < a; i++)
	{
		for (long long j = 1; j < b; j++)
		{
			for (long long k = 1; k < c; k++)
			{
				long long num = i*j*k;
				if (dp[num] == 0)
				{
					long long numSqrt = sqrt((long double)num);
					long long divisors = 2; // num itself and 1
					for (long long d = 2; d <= numSqrt; d++)
					{
						if (d*d == num)
							divisors++;
						else if (num % d == 0)
							divisors += 2; // the divisor and its counterpart 
					}
					dp[num] = divisors;
				}
				answer += dp[num] % MOD;
			}
		}
	}
	cout << (answer % MOD) - 1;
	return 0;
}