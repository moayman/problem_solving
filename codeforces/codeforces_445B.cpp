#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

// Connected components

vector<int> graph[51];
int visited[51];
long long answer = 1;

void DFS(int u)
{
	if (visited[u]) return;
	visited[u] = 1;
	for (size_t i = 0; i < graph[u].size(); i++)
	{
		if (!visited[graph[u][i]])
		{
			DFS(graph[u][i]);
			answer *= 2;
		}
	}
}

int main()
{
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (size_t j = 0; j < m; j++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (size_t j = 1; j < n; j++)
	{
		if (!visited[j])
			DFS(j);
	}
	cout << answer;
	return 0;
}
