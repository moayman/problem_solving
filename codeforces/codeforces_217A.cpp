#include <iostream>
using namespace std;

int x[100], y[100], n;
bool visited[100];

void dfs(int node)
{
	visited[node] = true;
	for (size_t i = 0; i < n; i++)
	{
		if (!visited[i] && (x[i] == x[node] || y[i] == y[node]))
			dfs(i);
	}
}

int numberOfGroups;

void main()
{
	int u, v;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			numberOfGroups++;
		}
	}
	cout << numberOfGroups - 1;
}

// This would never work because it is affected by the order of input
//#include <iostream>
//using namespace std;
//
//bool coordinates[1001][1001];
//int numberOfGroups;
//
//void main()
//{
//#ifdef AYMAN_PC
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
//	int n, u, v;
//	cin >> n;
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> u >> v;
//		if (!coordinates[0][v] && !coordinates[u][0])
//			numberOfGroups++;
//		coordinates[0][v] = true;
//		coordinates[u][0] = true;
//	}
//	cout << numberOfGroups - 1;
//}