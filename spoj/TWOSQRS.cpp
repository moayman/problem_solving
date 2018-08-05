#include <iostream>
#include <math.h>
using namespace std;

// two pointers approach
bool bruteforce(long long c, long long sq)
{
	long long i = sq, j = 0, inter;
	while (true)
	{
		inter = i * i + j * j;
		if (inter == c)
			return true;
		else if (inter < c)
			j++;
		else
			i--;
		if (j > i)
			break;
	}
	return false;
}

// Fermat: A number N is expressible as a sum of 2 squares if and only if in the prime factorization of N, every prime of the form(4k + 3) occurs an even number of times!
bool FermatTheorem(long long c, long long sq)
{
	for (long long i = 2; i < sq; i += 1 + (i & 1))
	{
		if (c%i == 0)
		{
			int count = 0;
			while (c % i == 0)
			{
				count++;
				c /= i;
			}
			if ((i == 3 || (i - 3) % 4 == 0) && count % 2 == 1) //factor is in the form of (4k+3) and not even
				return false;
		}
	}
	if (c > 1 && (c == 3 || (c - 3) % 4 == 0)) // n is prime and in the form(4k+3)
		return false;
	return true;
}

int main()
{
#ifdef AYMAN_PC
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long n, c;
	scanf("%lld", &n);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%lld", &c);
		long long sq = sqrt(c);
		printf("%s\n", bruteforce(c, sq) ? "Yes" : "No");
	}
	return 0;
}
