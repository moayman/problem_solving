#include <iostream>
#include <set>
#include <cstring>
using namespace std;

// DSU

int parent[50001], size[50001];

void init(int n)
{
	for (size_t i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	fill(size, size + n, 1);
}

int find(int u)
{
	return parent[u] == u ? u : parent[u] = find(parent[u]);
}

void join(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b)
		return;
	if (size[a] < size[b]) swap(a, b);
	size[a] += size[b];
	parent[b] = a;
}

int main()
{
	int t = 1, n, m, a, b;
	while (scanf("%d %d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
			break;
		init(n + 1);
		for (size_t j = 0; j < m; j++)
		{
			scanf("%d %d", &a, &b);
			join(a, b);
		}
		set<int> parentsFound;
		n++;
		for (size_t j = 1; j < n; j++)
		{
			parentsFound.insert(find(j));
		}
		printf("Case %d: %d\n", t++, parentsFound.size());
	}
	return 0;
}
