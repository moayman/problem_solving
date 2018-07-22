#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

#define N 100

int n, visited[N], vid, destination;

pair<int, int> edges[N][N], answer;

int gcd(int a, int b) {
	while (b != 0)  {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void DFS(int n, pair<int, int> ratio = { 1, 1 })
{
	if (visited[n] == vid) return;
	visited[n] = vid;
	if (n == destination)
	{
		answer = ratio;
		return;
	}
	for (size_t i = 0; i < N; i++)
	{
		if (edges[n][i].first != 0 && edges[n][i].second != 0)
			DFS(i, { ratio.first * edges[n][i].first, ratio.second * edges[n][i].second });
	}
}

int main()
{
	int i, j, ijgcd, answergcd;
	char c;
	string si, sj;
	map<string, int> data;
	while (cin >> c)
	{
		switch (c)
		{
		case '.':
			return 0;
			break;
		case '!':
			cin >> i >> si >> c >> j >> sj;
			if (data.find(si) == data.end())
				data[si] = n++;
			if (data.find(sj) == data.end())
				data[sj] = n++;
			ijgcd = gcd(i, j);
			i /= ijgcd, j /= ijgcd;
			edges[data[si]][data[sj]] = { i, j };
			edges[data[sj]][data[si]] = { j, i };
			break;
		case '?':
			cin >> si >> c >> sj;
			destination = data[sj];
			++vid;
			DFS(data[si]);
			if (visited[data[sj]] == vid)
			{
				answergcd = gcd(answer.first, answer.second);
				cout << answer.first / answergcd << " " << si << " = " << answer.second / answergcd << " " << sj << endl;
			}
			else
			{
				cout << "? " << si << " = ? " << sj << endl;
			}
			break;
		}
	}
	return 0;
}
