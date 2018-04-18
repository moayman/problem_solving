#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

// TSP with DP and bitmasking

#define INF 0x3f3f3f3f

#define getDist(x1,y1,x2,y2) sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)))

int n, x[10], y[10];
long double distances[10][10], dp[10][512], solution;
vector<int> sbuff, solutionOrder;

long double solve(int mask, int currentIndex, int numberOfNodes = 1, long double distance = 0)
{
	if (numberOfNodes == n)
	{
		if (distance < solution)
		{
			solution = distance;
			solutionOrder = sbuff;
		}
		return distance;
	}
	// This part is important because dp[currentIndex][mask] can have a 
	// non INF value while the upcoming distance is smaller than the 
	// memoed value
	// -------------------------------------------------------------------
	//                                 |||||||||||||||||||||||||||||||||||
	if (dp[currentIndex][mask] != INF && dp[currentIndex][mask] < distance)
		return dp[currentIndex][mask];
	for (size_t i = 0; i < n; i++)
	{
		if (!(1 << i & mask))
		{
			if (distances[currentIndex][i] == 0)
				distances[currentIndex][i] = distances[i][currentIndex] = getDist(x[i], y[i], x[currentIndex], y[currentIndex]) + 16;
			sbuff.push_back(i);
			dp[currentIndex][mask] = min(dp[currentIndex][mask], solve(mask | 1 << i, i, numberOfNodes + 1, distance + distances[currentIndex][i]));
			sbuff.pop_back();
		}
	}
	return dp[currentIndex][mask];
}

int main()
{
	int cnt = 0;
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		for (size_t i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i];
		}
		solution = INF;
		memset(distances, 0, sizeof distances);
		for (size_t i = 0; i < n; i++)
		{
			fill_n(&dp[0][0], 10 * 512, INF);
			sbuff.clear();
			sbuff.push_back(i);
			solve(1 << i, i);
		}
		printf("**********************************************************\n");
		printf("Network #%d\n", ++cnt);
		for (size_t i = 1; i < n; i++)
		{
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2Lf feet.\n", x[solutionOrder[i - 1]], y[solutionOrder[i - 1]], x[solutionOrder[i]], y[solutionOrder[i]], distances[solutionOrder[i]][solutionOrder[i - 1]]);
		}
		printf("Number of feet of cable required is %.2Lf.\n", solution);
	}
	return 0;
}
