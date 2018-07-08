#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// topological sort using BFS

#define N 1000001

int indegree[N], n, m, answer[N];
vector<int> data[N];

void init()
{
	memset(indegree, 0, sizeof indegree);
	for (size_t i = 0; i < N; i++)
	{
		data[i].clear();
	}
}

int topologicalSort()
{
	int index = 0;
	for (size_t i = 1; i < n + 1; i++)
	{
		if (indegree[i] == 0)
			answer[index++] = i;
	}
	for (size_t i = 0; i < index; i++)
	{
		for (size_t j = 0; j < data[answer[i]].size(); j++)
		{
			indegree[data[answer[i]][j]]--;
			if (indegree[data[answer[i]][j]] == 0)
				answer[index++] = data[answer[i]][j];
		}
	}
	return index;
}

int main()
{
	int a, b;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		init();
		for (size_t i = 0; i < m; i++)
		{
			cin >> a >> b;
			indegree[b]++;
			data[a].push_back(b);
		}
		if (topologicalSort() < n - 1)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			for (size_t i = 0; i < n; i++)
			{
				cout << answer[i] << endl;
			}
		}
	}
	return 0;
}