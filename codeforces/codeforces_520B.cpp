#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int moves = 0, n, m;
vector<pair<int, int> > data;
bool visited[100000];

void BFS()
{
	pair<int, int> current = { n, -1 };
	int i = 0;
	data.push_back(current);
	visited[current.first] = true;
	while (current.first != m)
	{
		if (current.first < m && !visited[current.first * 2])
		{
			data.push_back({ current.first * 2, i });
			visited[data.rbegin()->first] = true;
		}
		if (current.first != 0 && !visited[current.first - 1])
		{
			data.push_back({ current.first - 1, i });
			visited[data.rbegin()->first] = true;
		}
		current = data[++i];
	}
	while (current.second != -1)
	{
		moves++;
		current = data[current.second];
	}
}

int main()
{
	cin >> n >> m;
	BFS();
	cout << moves;
	return 0;
}