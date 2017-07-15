#include <iostream>
using namespace std;

#define N 10000
bool found[N];

void main()
{
	int n, m, u, v, centerNode = -1;
	cin >> n >> m;
	for (size_t i = 0; i < m; i++)
	{
		cin >> u >> v;
		found[u] = found[v] = true;
	}
	for (size_t i = 1; i <= n; i++)
	{
		if (!found[i])
		{
			centerNode = i;
			break;
		}
	}
	if (centerNode != -1)
	{
		cout << n - 1 << endl;
		for (size_t i = 1; i <= n; i++)
		{
			if (i != centerNode)
				cout << i << " " << centerNode << endl;
		}
	}
}