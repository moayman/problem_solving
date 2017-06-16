#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

long long a[200000], b[200000], A, B;

int n, m;

set<long long> data;

void update(long long value)
{
	size_t ai = upper_bound(a, a + n, value) - a, bi = upper_bound(b, b + m, value) - b;
	long long ascore = (n - ai) * 3 + (ai * 2), bscore = (m - bi) * 3 + (bi * 2);
	if (ascore - bscore > A - B || (ascore - bscore == A - B && ascore > A)) // <---- this was important
		A = ascore; B = bscore;
}


// n log(n)
void main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
		data.insert(a[i]);
	}
	cin >> m;
	for (size_t i = 0; i < m; i++)
	{
		cin >> b[i];
		data.insert(b[i]);
	}
	sort(a, a + n);
	sort(b, b + m);
	A = n * 3;
	B = m * 3;
	for (set<long long>::iterator it = data.begin(); it != data.end(); it++)
		update(*it);
	cout << A << ":" << B;
}
