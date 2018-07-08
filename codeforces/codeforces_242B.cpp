#include <iostream>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int l[100001], r[100001], n, minL = INF, maxR = -INF;

int main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> l[i] >> r[i];
		minL = min(minL, l[i]);
		maxR = max(maxR, r[i]);
	}
	for (size_t i = 0; i < n; i++)
	{
		if (l[i] <= minL && r[i] >= maxR)
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << -1;
	return 0;
}