#include <iostream>
#include <set>
using namespace std;

set<long long> commonDivisors;

void updateR(long long& r0, long long& r1, const long long& r){
	long long t = r0 - r*r1;
	r0 = r1;
	r1 = t;
}

//Extended Euclidean Algorithm
long long eGCD(long long r0, long long r1, long long& x0, long long& y0){
	long long y1 = x0 = 1, x1 = y0 = 0;
	while (r1){
		long long r = r0 / r1;
		updateR(r0, r1, r);
		updateR(x0, x1, r);
		updateR(y0, y1, r);
	}
	return r0;
}

void divisors(long long n)
{
	for (long long i = 1; i <= n / i; i++)
	{
		if (n % i == 0)
		{
			commonDivisors.insert(i);
			commonDivisors.insert(n / i);
		}
	}
}

int main()
{
	long long a, b, x, y, n, f, t;
	scanf("%lld %lld %lld", &a, &b, &n);
	long long gcd = eGCD(a, b, x, y);
	divisors(gcd);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%lld %lld", &f, &t);
		if (f > gcd)
			printf("-1\n");
		else if (f == gcd || t == gcd)
			printf("%lld\n", gcd);
		else if (commonDivisors.find(t) != commonDivisors.end())
			printf("%lld\n", t);
		else
		{
			set<long long>::iterator output;
			long long answer = -1;
			while (f <= t)
			{
				long long m = f + (t - f) / 2;
				output = commonDivisors.lower_bound(m);
				if (output == commonDivisors.end() || *output > t)
					t = m - 1;
				else
					f = m + 1;
				if (output != commonDivisors.end() && *output <= t)
					answer = *output;
			}
			printf("%lld\n", answer);
		}
	}
	return 0;
}