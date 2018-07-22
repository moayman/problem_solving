#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// DSU find max size

int parent[30001], size[30001], answer;

void init(int n)
{
	for (size_t i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	fill(size, size + n, 1);
	answer = 1;
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
	answer = max(answer, size[a]);
	parent[b] = a;
}

int main()
{
	int t, n, m, a, b;
	scanf("%d", &t);
	for (size_t i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;
		init(n + 1);
		for (size_t j = 0; j < m; j++)
		{
			scanf("%d %d", &a, &b);
			join(a, b);
		}
		printf("%d\n", answer);
	}
	return 0;
}
