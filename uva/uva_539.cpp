#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

size_t n, m;
int maxRoadLength;
bool isEdgeTaken[25][25], roads[25][25];

void settlersOfCatan(unsigned int currentNode, int l = 0)
{
	if (l > maxRoadLength)
	{
		maxRoadLength = l;
	}
	for (size_t i = 0; i < 25; i++)
	{
		if (roads[currentNode][i] && !isEdgeTaken[currentNode][i])
		{
			isEdgeTaken[currentNode][i] = true;
			isEdgeTaken[i][currentNode] = true;
			settlersOfCatan(i, l + 1);
			isEdgeTaken[currentNode][i] = false;
			isEdgeTaken[i][currentNode] = false;
		}
	}
}

int main()
{
	unsigned int city1, city2;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		for (size_t i = 0; i < 25; i++)
		{
			for (size_t j = 0; j < 25; j++)
			{
				roads[i][j] = false;
			}
		}
		maxRoadLength = 0;
		for (size_t i = 0; i < m; i++)
		{
			cin >> city1 >> city2;
			roads[city1][city2] = true;
			roads[city2][city1] = true;
		}
		for (size_t i = 0; i < n; i++)
		{
			settlersOfCatan(i);
		}
		cout << maxRoadLength << endl;
	}
	return 0;
}