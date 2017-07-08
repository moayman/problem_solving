#include <iostream>
#include <vector>
using namespace std;

const int N = 2000;
bool visisted[N];
vector<int> graph[N];
int maxDepth = 1;

void DFS(int u, int d = 1)
{
	maxDepth = max(d, maxDepth);
	visisted[u] = true;
	for (size_t i = 0; i < graph[u].size(); i++)
	{
		if (!visisted[graph[u][i]])
			DFS(graph[u][i], d + 1);
	}
}

int main()
{
#ifdef ALIEN
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
	int n, input;
	vector<int> boss;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		if (input != -1)
			graph[input - 1].push_back(i);
		else
			boss.push_back(i);
	}
	for (size_t i = 0; i < boss.size(); i++)
	{
		DFS(boss[i]);
	}
	cout << maxDepth;
	return 0;
}
