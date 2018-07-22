#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f
#define N 20
int tax[N];
vector<vector<int>> adjMat;
int ks[N][N];
int nodesCount;
string townNames[N];

void floyd(){
	vector<vector<int> > & ret = adjMat;
	for (int k = 0; k < nodesCount; ++k)
	{
		for (int i = 0; i < nodesCount; ++i)
		{
			for (int j = 0; j < nodesCount; ++j)
			{
				if (ret[i][j] > ret[i][k] + ret[k][j])
				{
					ret[i][j] = ret[i][k] + ret[k][j];
					ks[i][j] = k;
				}
			}
		}
	}
}

void printPath(int from, int to)
{
	if (from != to)
	{
		if (ks[from][to] == -1)
		{
			printf("%s ", townNames[from].c_str());
			return;
		}
		printPath(from, ks[from][to]);
		printPath(ks[from][to], to);
	}
}

int main()
{
	int t, input, paths, queries, passengers;
	string town, from, to;
	cin >> t;
	adjMat.resize(N, vector<int>(N, INF));
	for (size_t test = 0; test < t; test++)
	{
		cin >> nodesCount;
		for (int i = 0; i < nodesCount; ++i)
		{
			for (int j = 0; j < nodesCount; ++j)
				adjMat[i][j] = INF;
		}
		memset(ks, -1, sizeof ks);
		map<string, int> towns;
		for (size_t i = 0; i < nodesCount; i++)
		{
			cin >> town >> input;
			towns[town] = i;
			tax[i] = input;
			townNames[i] = town;
		}
		cin >> paths;
		for (size_t i = 0; i < paths; i++)
		{
			cin >> from >> to >> input;
			int fromIndex = towns[from], toIndex = towns[to];
			adjMat[fromIndex][toIndex] = (input * 2) + tax[toIndex];
			adjMat[toIndex][fromIndex] = (input * 2) + tax[fromIndex];
		}
		floyd();
		cin >> queries;
		printf("Map #%d\n", test + 1);
		for (size_t i = 0; i < queries; i++)
		{
			cin >> from >> to >> passengers;
			printf("Query #%d\n", i + 1);
			printPath(towns[from], towns[to]);
			printf("%s\n", to.c_str());
			if (towns[from] == towns[to])
				printf("Each passenger has to pay : %.2f taka\n", ((float)tax[towns[from]] * 1.1) / (float)passengers);
			else
				printf("Each passenger has to pay : %.2f taka\n", (((float)adjMat[towns[from]][towns[to]] + (float)tax[towns[from]]) * 1.1) / (float)passengers);
		}
		if (test != t - 1)
			printf("\n");
	}
	return 0;
}
