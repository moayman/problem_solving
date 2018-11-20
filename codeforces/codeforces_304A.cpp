#include <iostream>
#include <math.h>
using namespace std;

int ans;
double n, c;

int main()
{
	cin >> n;
	for (int a = 1; a <= n; a++)
	{
		for (int b = a; b <= n; b++)
		{
			c = sqrt(a*a + b*b);
			if (c <= n && floor(c) == ceil(c))
				ans++;
		}
	}
	cout << ans;
	return 0;
}