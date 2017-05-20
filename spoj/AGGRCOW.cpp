#include <iostream>
#include <algorithm>
using namespace std;

// log (1e9) * cows * log (n)
// TTTFFFFF
// Keep trying until you fail
// distance 1 works 2 works 3 works 4 doesn't

int d[100000], n, c;

bool can(int width, int cows)
{
	int cur = d[0];
	cows--;
	while (cows)
	{
		int index = lower_bound(d, d + n, cur + width) - d; // get the index of the thing that is right above cur + width 
		if (index == n) return false;
		cur = d[index];
		cows--;
	}
	return true;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &n, &c);
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", &d[i]);
		}
		sort(d, d + n);
		int s = 0, e = 1e9;
		while (s < e)
		{
			int mid = s + (e - s + 1) / 2;
			if (can(mid, c)) s = mid;
			else e = mid - 1;
		}
		printf("%d\n", s);
	}
	return 0;
}
