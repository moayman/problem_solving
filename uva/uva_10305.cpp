#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// topological sort using DFS
// order by appearance in testcase

#define N 101

int n, m, visited[N];
vector<vector<int> > data;
vector<int> answer;

void init()
{
	memset(visited, 0, sizeof visited);
	data.clear(); data.resize(N);
	answer.clear();
}

void DFS(int u)
{
	if (visited[u] == 1) return;
	visited[u] = 1;
	for (size_t i = 0; i < data[u].size(); i++)
	{
		DFS(data[u][i]);
	}
	answer.push_back(u);
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
			data[a].push_back(b);
		}
		for (size_t i = 1; i < n + 1; i++)
		{
			if (visited[i] == 0)
				DFS(i);
		}
		bool space = false;
		for (auto it = answer.rbegin(); it != answer.rend(); it++)
		{
			if (space)
				cout << " ";
			space = true;
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}