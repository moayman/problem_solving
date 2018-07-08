#include <iostream>
using namespace std;


int main()
{
	int a, b, n;
	cin >> a >> b >> n;
	for (size_t i = 0; i < 10; i++)
	{
		if ((a * 10 + i) % b == 0)
		{
			n--;
			cout << (a * 10 + i);
			for (size_t i = 0; i < n; i++)
				cout << 0;
			return 0;
		}
	}
	cout << -1;
	return 0;
}