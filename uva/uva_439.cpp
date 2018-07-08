#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int t = 1;

struct node
{
	int c, r, m;
};

int visited[8][8];

char sc, ec;
int sr, er;

int BFS()
{
	node current;
	int i = 0;
	vector<node> toprocess;
	toprocess.push_back({ sc - 'a', sr - 1, 0 });
	current = toprocess[i];
	while (current.c != ec - 'a' || current.r != er - 1)
	{
		if (current.c + 1 < 8)
		{
			if (current.r + 2 < 8)
			{
				if (visited[current.c + 1][current.r + 2] != t)
				{
					toprocess.push_back({ current.c + 1, current.r + 2, current.m + 1 });
					visited[current.c + 1][current.r + 2] = t;
				}
			}
			if (current.r - 2 > -1)
			{
				if (visited[current.c + 1][current.r - 2] != t)
				{
					toprocess.push_back({ current.c + 1, current.r - 2, current.m + 1 });
					visited[current.c + 1][current.r - 2] = t;
				}
			}
		}
		if (current.c - 1 > -1)
		{
			if (current.r + 2 < 8)
			{
				if (visited[current.c - 1][current.r + 2] != t)
				{
					toprocess.push_back({ current.c - 1, current.r + 2, current.m + 1 });
					visited[current.c - 1][current.r + 2] = t;
				}
			}
			if (current.r - 2 > -1)
			{
				if (visited[current.c - 1][current.r - 2] != t)
				{
					toprocess.push_back({ current.c - 1, current.r - 2, current.m + 1 });
					visited[current.c - 1][current.r - 2] = t;
				}
			}
		}
		if (current.r + 1 < 8)
		{
			if (current.c + 2 < 8)
			{
				if (visited[current.c + 2][current.r + 1] != t)
				{
					toprocess.push_back({ current.c + 2, current.r + 1, current.m + 1 });
					visited[current.c + 2][current.r + 1] = t;
				}
			}
			if (current.c - 2 > -1)
			{
				if (visited[current.c - 2][current.r + 1] != t)
				{
					toprocess.push_back({ current.c - 2, current.r + 1, current.m + 1 });
					visited[current.c - 2][current.r + 1] = t;
				}
			}
		}
		if (current.r - 1 > -1)
		{
			if (current.c + 2 < 8)
			{
				if (visited[current.c + 2][current.r - 1] != t)
				{
					toprocess.push_back({ current.c + 2, current.r - 1, current.m + 1 });
					visited[current.c + 2][current.r - 1] = t;
				}
			}
			if (current.c - 2 > -1)
			{
				if (visited[current.c - 2][current.r - 1] != t)
				{
					toprocess.push_back({ current.c - 2, current.r - 1, current.m + 1 });
					visited[current.c - 2][current.r - 1] = t;
				}
			}
		}
		current = toprocess[++i];
	}
	return current.m;
}

int main()
{
	while (cin >> sc >> sr >> ec >> er)
	{
		cout << "To get from " << sc << sr << " to " << ec << er << " takes " << BFS() << " knight moves." << endl;
		t++;
	}
	return 0;
}