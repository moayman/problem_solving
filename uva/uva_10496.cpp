#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

// Check UVA 216

#define INF 0x3f3f3f3f

#define getDist(x1,y1,x2,y2) (abs(x1-x2) + abs(y1-y2))

int t, n, x[25], y[25];
int distances[25][25], dp[25][1025], solution;

int solve(int mask = 1, int currentIndex = 0, int numberOfNodes = 1, int distance = 0)
{
	if (numberOfNodes == n)
	{
		if (distances[currentIndex][0] == 0)
			distances[currentIndex][0] = distances[0][currentIndex] = getDist(x[0], y[0], x[currentIndex], y[currentIndex]);
		if (distance + distances[currentIndex][0] < solution)
		{
			solution = distance + distances[currentIndex][0];
		}
		return distance + distances[currentIndex][0];
	}
	if (dp[currentIndex][mask] != INF && dp[currentIndex][mask] < distance)
		return dp[currentIndex][mask];
	for (size_t i = 0; i < n; i++)
	{
		if (!(1 << i & mask))
		{
			if (distances[currentIndex][i] == 0)
				distances[currentIndex][i] = distances[i][currentIndex] = getDist(x[i], y[i], x[currentIndex], y[currentIndex]);
			dp[currentIndex][mask] = min(dp[currentIndex][mask], solve(mask | 1 << i, i, numberOfNodes + 1, distance + distances[currentIndex][i]));
		}
	}
	return dp[currentIndex][mask];
}

int main()
{
	while (cin >> t)
	{
		for (size_t j = 0; j < t; j++)
		{
			cin >> x[0] >> y[0];
			cin >> x[0] >> y[0];
			cin >> n;
			n++;
			for (size_t i = 1; i < n; i++)
			{
				cin >> x[i] >> y[i];
			}
			solution = INF;
			memset(distances, 0, sizeof distances);
			fill_n(&dp[0][0], 25 * 1025, INF);
			solve();
			printf("The shortest path has length %d\n", solution);
		}
	}
	return 0;
}
