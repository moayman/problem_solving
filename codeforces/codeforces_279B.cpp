#include <iostream>
using namespace std;

int n, t, data[100000], sum[100000];

bool can(int d)
{
	for (size_t i = 0; i < n - d + 1; i++)
	{
		if (sum[i + d - 1] - sum[i] + data[i] <= t)
			return true;
	}
	return false;
}

void main()
{
	cin >> n >> t;
	for (size_t i = 0; i < n; i++)
	{
		cin >> data[i];
		if (i)
			sum[i] = data[i] + sum[i - 1];
		else
			sum[i] = data[i];
	}
	int s = 0, e = n;
	while (s < e)
	{
		int mid = s + (e - s + 1) / 2;
		if (can(mid)) s = mid;
		else e = mid - 1;
	}
	printf("%d", s);
}
