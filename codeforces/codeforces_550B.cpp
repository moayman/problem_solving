#include <iostream>
using namespace std;

bool atLeast2Problems(long long num)
{
	long long bitCount = 0;
	while (num && bitCount < 2)
	{
		bitCount += num & 1;
		num >>= 1;
	}
	return bitCount > 1;
}

void main()
{
	long long n, l, r, x, difficulties[15], answer = 0, max, total, maxDiff, minDiff, bits, bitCount;
	cin >> n >> l >> r >> x;
	for (size_t i = 0; i < n; i++)
	{
		cin >> difficulties[i];
	}
	max = 1 << n;
	for (long long i = 3; i < max; i++)
	{
		if (atLeast2Problems(i))
		{
			total = 0;
			maxDiff = -1; minDiff = 1e9;
			bits = i;
			bitCount = 0;
			while (bits)
			{
				if (bits & 1)
				{
					minDiff = difficulties[bitCount] < minDiff ? difficulties[bitCount] : minDiff;
					maxDiff = difficulties[bitCount] > maxDiff ? difficulties[bitCount] : maxDiff;
					total += difficulties[bitCount];
				}
				bitCount++;
				bits >>= 1;
			}
			if (maxDiff - minDiff >= x && total >= l && total <= r)
				answer++;
		}
	}
	cout << answer;
}