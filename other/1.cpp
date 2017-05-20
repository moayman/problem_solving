//https://www.topcoder.com/community/data-science/data-science-tutorials/an-introduction-to-recursion-part-2/
#include <iostream>
using namespace std;

int n, m, sx, sy, ex, ey;
bool gridObs[8][8], visited[8][8], solved;

void go(int cx = sx, int cy = sy)
{
	if (cx == ex && cy == ey)
	{
		solved = true;
		return;
	}
	//UP
	if (cy > 0 && !gridObs[cx][cy - 1] && !visited[cx][cy - 1])
	{
		visited[cx][cy - 1] = true;
		go(cx, cy - 1);
		if (solved)
			return;
		visited[cx][cy - 1] = false;
	}
	//DOWN
	if (cy < m - 1 && !gridObs[cx][cy + 1] && !visited[cx][cy + 1])
	{
		visited[cx][cy + 1] = true;
		go(cx, cy + 1);
		if (solved)
			return;
		visited[cx][cy + 1] = false;
	}
	//RIGHT
	if (cx < n - 1 && !gridObs[cx + 1][cy] && !visited[cx + 1][cy])
	{
		visited[cx + 1][cy] = true;
		go(cx + 1, cy);
		if (solved)
			return;
		visited[cx + 1][cy] = false;
	}
	//LEFT
	if (cx > 0 && !gridObs[cx - 1][cy] && !visited[cx - 1][cy])
	{
		visited[cx - 1][cy] = true;
		go(cx - 1, cy);
		if (solved)
			return;
		visited[cx - 1][cy] = false;
	}
}

int main()
{
	char input;
	while (cin >> n >> m)
	{
		solved = false;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				cin >> input;
				switch (input)
				{
				case '*':
					gridObs[i][j] = true;
					break;
				case 'S':
					sx = i; sy = j;
					visited[i][j] = true;
					break;
				case 'E':
					ex = i; ey = j;
					break;
				}
			}
		}
		go();
		cout << ((solved) ? "YES" : "NO");
	}
	return 0;
}
