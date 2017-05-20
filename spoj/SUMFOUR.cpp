#include <iostream>
#include <algorithm>
using namespace std;

// (2500 * 2500) * log(2500 * 2500) will not TLE
// a + b + c + d = 0 --> a + b = - (c + d)
// loop on a + b and check for - (a + b) in c + d array using binary search (lower, upperbound)

int n;
int a[2500], b[2500], c[2500], d[2500];
int ab[2500 * 2500], cd[2500 * 2500];

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++)
			scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
		int idx = 0;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ab[idx++] = a[i] + b[j];
		idx = 0;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cd[idx++] = c[i] + d[j];
		sort(cd, cd + idx);
		long long ans = 0;
		for (int i = 0; i < idx; i++) {
			int xx = upper_bound(cd, cd + idx, -ab[i]) - cd;
			int yy = lower_bound(cd, cd + idx, -ab[i]) - cd;
			ans += (xx - yy);
		}
		printf("%lld\n", ans);
	}
	return 0;
}