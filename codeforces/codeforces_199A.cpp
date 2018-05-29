#include <iostream>
using namespace std;

int main()
{
	int f0 = 0, f1 = 1, f = 0, n;
	cin >> n;
	while (f < n)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;
	}
	cout << f0 << ' ' << f - f0 << ' ' << 0;
	return 0;
}