#include <iostream>
using namespace std;

int main()
{
	int n, m, ans = 0;
	cin >> n >> m;
	for (size_t a = 0; a < 33; a++)
	{
		for (size_t b = 0; b < 33; b++)
		{
			if (n == a * a + b && m == b * b + a)
				ans++;
		}
	}
	cout << ans;
	return 0;
}