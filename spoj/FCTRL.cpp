#include <iostream>
using namespace std;

int t, n;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int ans = 0;
		while (n)
		{
			n /= 5;
			ans += n;
		}
		printf("%d\n", ans);
	}
	return 0;
}
