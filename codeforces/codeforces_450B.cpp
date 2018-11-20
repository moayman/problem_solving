#include <iostream>
using namespace std;

#define MOD 1000000007

long long sol[6];

int main()
{
	long long x, y, n, current, prev;
	cin >> x >> y >> n;
	sol[0] = (x + MOD) % MOD;
	sol[1] = (y + MOD) % MOD;
	for (size_t i = 2; i < 6; i++)
		sol[i] = (sol[i - 1] - sol[i - 2] + MOD) % MOD;
	cout << sol[(n - 1) % 6];
	return 0;
}
