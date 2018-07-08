#include <iostream>
using namespace std;

int t = 1, n;
int visited[25][25], data[25][25];

void DFS(int i, int j)
{
	if (i > -1 && i < n && j > -1 && j < n && data[i][j] == 1 && visited[i][j] != t)
	{
		visited[i][j] = t;
		DFS(i + 1, j);
		DFS(i - 1, j);
		DFS(i, j + 1);
		DFS(i, j - 1);
		DFS(i - 1, j + 1);
		DFS(i + 1, j - 1);
		DFS(i - 1, j - 1);
		DFS(i + 1, j + 1);
	}
}

int main()
{
	char input;
	while (cin >> n)
	{
		int eagles = 0;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				cin >> input;
				data[i][j] = input - '0';
			}
		}
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (data[i][j] == 1 && visited[i][j] != t)
				{
					DFS(i, j);
					eagles++;
				}
			}
		}
		cout << "Image number " << t++ << " contains " << eagles << " war eagles." << endl;
	}
	return 0;
}