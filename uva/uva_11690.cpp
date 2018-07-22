#include <iostream>
#include <set>
#include <cstring>
using namespace std;

// DSU
// DFS solution always TLE

int parent[10001], size[10001], owe[10001];

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
	int t, n, m, a, b;
	scanf("%d", &t);
	for (size_t i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		init(n);
		for (size_t j = 0; j < n; j++)
		{
			scanf("%d", &a);
			owe[j] = a;
		}
		for (size_t j = 0; j < m; j++)
		{
			scanf("%d %d", &a, &b);
			join(a, b);
		}
		set<int> parentsFound;
		for (size_t j = 0; j < n; j++)
		{
			int p = find(j);
			if (p != j)
				owe[p] += owe[j];
			parentsFound.insert(p);
		}
		bool possible = true;
		for (auto it = parentsFound.begin(); it != parentsFound.end(); it++)
		{
			if (owe[*it] != 0)
			{
				possible = false;
				break;
			}
		}
		if (possible)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
