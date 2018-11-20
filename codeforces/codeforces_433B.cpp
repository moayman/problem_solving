#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100005

vector<long long> q1, q2;
long long n, m, l, r, q, input;

int main()
{
	q1.reserve(MAX);
	q2.reserve(MAX);
	q1.push_back(0);
	q2.push_back(0);
	cin >> n;
	for (long long i = 1; i <= n; i++)
	{
		cin >> input;
		q2.push_back(input);
		q1.push_back(input + q1[i - 1]);
	}
	sort(q2.begin(), q2.end());
	for (long long i = 1; i <= n; i++)
	{
		q2[i] += q2[i - 1];
	}
	cin >> m;
	for (long long i = 0; i < m; i++)
	{
		cin >> q >> l >> r;
		if (q == 1)
		{
			cout << q1[r] - q1[l - 1] << endl;
		}
		else if (q == 2)
		{
			cout << q2[r] - q2[l - 1] << endl;
		}
	}
	return 0;
}
