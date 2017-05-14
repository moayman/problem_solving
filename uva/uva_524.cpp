#include <iostream>
#include <cmath>
using namespace std;

unsigned int solution[16] = { 1 }, n;
int isPrime[32] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
bool isNumberTaken[16] = { true };

bool checkPrime(unsigned int toCheck)
{
	if (isPrime[toCheck] != -1)
		return isPrime[toCheck];
	unsigned int max = sqrt(toCheck);
	for (unsigned int i = 2; i <= max; i++)
	{
		if (toCheck % i == 0)
		{
			isPrime[toCheck] = 0;
			return false;
		}
	}
	isPrime[toCheck] = 1;
	return true;
}

void primeRing(int N = 0)
{
	if (n - 1 == N)
	{
		if (checkPrime(solution[N] + solution[0]))
		{
			for (size_t i = 0; i < n; i++)
			{
				cout << solution[i];
				if (n - 1 != i)
					cout << " ";
			}
			cout << endl;
		}
		return;
	}
	for (size_t i = 1; i <= n; i++)
	{
		if (!isNumberTaken[i - 1] && checkPrime(i + solution[N]))
		{
			isNumberTaken[i - 1] = true;
			solution[N + 1] = i;
			primeRing(N + 1);
			isNumberTaken[i - 1] = false;
		}
	}
}

int main()
{
	isNumberTaken[0] = true;
	unsigned int caseNumber = 1;
	while (cin >> n)
	{
		if (caseNumber > 1)
			cout << endl;
		cout << "Case " << caseNumber++ << ":" << endl;
		primeRing();
	}
	return 0;
}