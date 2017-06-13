#include <iostream>
using namespace std;


long long data[5000000], llc[5000000], n, s, answer;
bool rr[5000000];

int main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> data[i];
		s += data[i];
	}
	if (s % 3 == 0)
	{
		s /= 3;
		long long r = 0, l = 0, lc = 0;
		for (size_t i = 0; i < n; i++)
		{
			r += data[i];
			rr[i] = r == s;
		}
		for (long long i = n - 1; i > -1; i--)
		{
			l += data[i];
			if (l == s)
			{
				++lc;
			}
			llc[i] = lc;
		}
		for (size_t i = 0; i < n; i++)
		{
			if (rr[i])
			{
				if (i + 2 < n)
					answer += llc[i + 2];
			}
		}
	}
	cout << answer;
	return 0;
}
