#include <iostream>
using namespace std;

bool isPrime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2, q = x / i; q >= i; q = x / ++i)
	{
		if (x == q * i)
			return false;
	}
	return true;
}

int nextPrime(int x)
{
	while (!isPrime(++x)) {}
	return x;
}



int main()
{
	int n, m;
	cin >> n >> m;
	if (m == nextPrime(n))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}