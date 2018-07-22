#include <iostream>
#include <cstring>
using namespace std;

int visited[201], head[201], nxt[200000], to[200000], ne;

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
	int n, l, a, b;
	bool isBiPartite;
	while (cin >> n)
	{
		if (n == 0)
			break;
		cin >> l;
		init();
		for (size_t i = 0; i < l; i++)
		{
			cin >> a >> b;
			addBiEdge(a, b);
		}
		isBiPartite = true;
		for (size_t i = 0; i < n && isBiPartite; i++)
		{
			if (visited[i] == -1)
				isBiPartite &= DFS(i);
		}
		if (isBiPartite)
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
	}
	return 0;
}
