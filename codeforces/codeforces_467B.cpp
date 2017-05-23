#include <iostream>
using namespace std;

void main()
{
	int toProcess, bitCount, k, n, m, ans = 0, data[1001], ref;
	cin >> n >> m >> k;
	m++;
	for (size_t i = 0; i < m; i++)
	{
		cin >> data[i];
	}
	m--;
	for (size_t i = 0; i < m; i++)
	{
		bitCount = 0;
		toProcess = data[m] ^ data[i];
		while (toProcess)
		{
			bitCount += (toProcess & 1);
			toProcess >>= 1;
		}
		if (bitCount <= k)
			ans++;
	}
	cout << ans;
}
