#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f
#define N 101
int nodes[N];
vector<vector<int>> adjMat;
int nodesCount;

void floyd(){
	vector<vector<int> > & ret = adjMat;
	for (int k = 1; k < nodesCount; ++k)
		for (int i = 1; i < nodesCount; ++i)
			for (int j = 1; j < nodesCount; ++j)
				ret[i][j] = min(ret[i][j], ret[i][k] + ret[k][j]);
}

double getAvg()
{
	long long sum = 0;
	long long number = 0;
	for (int i = 1; i < nodesCount; ++i)
	{
		for (int j = 1; j < nodesCount; ++j)
		{
			if (i != j && adjMat[i][j] != INF)
			{
				sum += adjMat[i][j];
				++number;
			}
		}
	}
	return (double)sum / (double)number;
}

int main()
{
	int a, b, t = 1;
	adjMat.resize(N, vector<int>(N, INF));
	while (cin >> a >> b && a != 0 && b != 0)
	{
		nodesCount = 1;
		for (int i = 1; i < N; ++i)
		{
			for (int j = 1; j < N; ++j)
				adjMat[i][j] = INF;
			nodes[i] = 0;
		}
		do {
			adjMat[nodes[a] == 0 ? nodes[a] = nodesCount++ : nodes[a]][nodes[b] == 0 ? nodes[b] = nodesCount++ : nodes[b]] = 1;
			cin >> a >> b;
		} while (a != 0 && b != 0);
		floyd();
		printf("Case %d: average length between pages = %.3f clicks\n", t++, getAvg());
	}
	return 0;
}
