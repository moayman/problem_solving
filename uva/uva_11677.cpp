#include <iostream>
using namespace std;

int main()
{
	unsigned long long h1, m1, h2, m2;
	cin >> h1 >> m1 >> h2 >> m2;
	do
	{
		unsigned long long M1 = m1 + (h1 * 60), M2 = m2 + (h2 * 60);
		if (M2 < M1)
			M2 += 1440; // 24*60
		cout << M2 - M1 << endl;
		cin >> h1 >> m1 >> h2 >> m2;
	} while (h1 != 0 || h2 != 0 || m1 != 0 || m2 != 0);
	return 0;
}