#include <iostream>
#include <cstring>
using namespace std;

#define MAX 10000000
bool primes[MAX];
int n;
long long input;

void sieve()
{
	memset(primes, true, sizeof primes);
	primes[0] = false; primes[1] = false;
	cout << 2 << " ";
	n--;
	for (int i = 4; i < MAX; i += 2)
	{
		primes[i] = false;
	}
	for (int i = 3; i < MAX && n != 0; i += 2)
	{
		if (primes[i] == true)
		{
			cout << i << " ";
			n--;
			for (int j = i + i; j < MAX; j += i)
			{
				primes[j] = false;
			}
		}
	}
}

int main()
{
	cin >> n;
	sieve();
	return 0;
}
