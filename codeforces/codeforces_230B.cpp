#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

#define MAX 1000000
bool primes[MAX];
int n;
long long input;

void sieve()
{
	memset(primes, true, sizeof primes);
	primes[0] = false; primes[1] = false;
	for (int i = 4; i < MAX; i += 2)
	{
		primes[i] = false;
	}
	for (int i = 3; i < MAX; i += 2)
	{
		if (primes[i] == true)
		{
			for (int j = i + i; j < MAX; j += i)
			{
				primes[j] = false;
			}
		}
	}
}

inline bool isTPrime(long long& number)
{
	long long sq = sqrtl(number);
	return primes[sq] && sq * sq == number;
}

int main()
{
	sieve();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (isTPrime(input))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
