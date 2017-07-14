#include <iostream>
#include <functional>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 500

int n, m;
bool trainRoutes[N][N], busRoutes[N][N];

int shortestBusPath()
{
	priority_queue<pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;

	vector<int> dist(N, 0x7FFFFFFF);

	pq.push(pair<int, int>(0, 0));
	dist[0] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for (size_t i = 0; i < n; i++)
		{
			if (i != u && busRoutes[u][i])
			{
				if (dist[i] > dist[u] + 1)
				{
					dist[i] = dist[u] + 1;
					pq.push(pair<int, int>(dist[u] + 1, i));
				}
			}
		}
	}
	if (dist[n - 1] != 0x7FFFFFFF)
		return dist[n - 1];
	else
		return -1;
}

int shortestTrainPath()
{
	priority_queue<pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;

	vector<int> dist(N, 0x7FFFFFFF);

	pq.push(pair<int, int>(0, 0));
	dist[0] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for (size_t i = 0; i < n; i++)
		{
			if (i != u && trainRoutes[u][i])
			{
				if (dist[i] > dist[u] + 1)
				{
					dist[i] = dist[u] + 1;
					pq.push(pair<int, int>(dist[u] + 1, i));
				}
			}
		}
	}
	if (dist[n - 1] != 0x7FFFFFFF)
		return dist[n - 1];
	else
		return -1;
}

void main()
{
	cin >> n >> m;
	int u, v;
	memset(busRoutes, -1, sizeof busRoutes);
	for (size_t i = 0; i < m; i++)
	{
		cin >> u >> v;
		trainRoutes[u - 1][v - 1] = true;
		trainRoutes[v - 1][u - 1] = true;
		busRoutes[u - 1][v - 1] = false;
		busRoutes[v - 1][u - 1] = false;
	}
	int busDistance = shortestBusPath(), trainDistance = shortestTrainPath();
	if (busDistance == -1 || trainDistance == -1)
		cout << -1;
	else
		cout << max(busDistance, trainDistance);
}