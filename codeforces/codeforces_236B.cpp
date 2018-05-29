#include <iostream>
#include <cstring>
using namespace std;

int dp[1000001];
int primes[1000];
int numberOfPrimes;

int SieveOfEratosthenes()
{
	bool prime[1001];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p*p <= 1000; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * 2; i <= 1000; i += p)
				prime[i] = false;
		}
	}

	int pindex = 0;
	for (int p = 2; p <= 1000; p++)
	if (prime[p])
		primes[pindex++] = p;
	return pindex;
}

int getDivisors(int n)
{
	if (dp[n] != 0)
		return dp[n];
	int numberOfDivisors = 1;
	for (size_t i = 0; i < numberOfPrimes; i++)
	{
		int currentDivisors = 0;
		while (n % primes[i] == 0)
		{
			n /= primes[i];
			currentDivisors++;
		}
		numberOfDivisors *= currentDivisors + 1;
	}
	return dp[n] = numberOfDivisors;
}

int main()
{
	numberOfPrimes = SieveOfEratosthenes();
	int a, b, c, answer = 0;
	cin >> a >> b >> c;
	a++; b++; c++;
	for (int i = 1; i < a; i++)
	{
		for (int j = 1; j < b; j++)
		{
			for (int k = 1; k < c; k++)
			{
				answer += getDivisors(i*j*k) % 1073741824;
			}
		}
	}
	cout << answer % 1073741824;
	return 0;
}