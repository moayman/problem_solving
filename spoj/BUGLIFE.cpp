#include <iostream>
#include <cstring>
using namespace std;

int visited[2001], head[2001], nxt[2000000], to[2000000], ne;

void init()
{
	ne = 0;
	memset(visited, -1, sizeof visited);
	memset(head, -1, sizeof head);
}

void addEdge(int f, int t)
{
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}

void addBiEdge(int a, int b)
{
	addEdge(a, b);
	addEdge(b, a);
}

bool DFS(int u, int c = 0)
{
	if (visited[u] != -1) return visited[u] == c;
	visited[u] = c;
	for (int k = head[u], v; k != -1, v = to[k]; k = nxt[k])
	{
		if (!DFS(v, 1 - c))
			return false;
	}
	return true;
}

int main()
{
	int t, n, m, a, b;
	bool isBiPartite;
	cin >> t;
	for (size_t test = 0; test < t; test++)
	{
		cin >> n >> m;
		init();
		for (size_t i = 0; i < m; i++)
		{
			cin >> a >> b;
			addBiEdge(a, b);
		}
		n++;
		isBiPartite = true;
		for (size_t i = 1; i < n && isBiPartite; i++)
		{
			if (visited[i] == -1)
				isBiPartite &= DFS(i);
		}
		cout << "Scenario #" << test + 1 << ":" << endl;
		if (isBiPartite)
			cout << "No suspicious bugs found!" << endl;
		else
			cout << "Suspicious bugs found!" << endl;
	}
	return 0;
}