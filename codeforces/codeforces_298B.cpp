#include <iostream>
using namespace std;

int main()
{
	int n, sx, sy, dx, dy, cx, cy, time = 0;
	cin >> n >> sx >> sy >> dx >> dy;
	cx = sx; cy = sy;
	char d1 = '0', d2 = '0', d;
	if (sx < dx)
		d1 = 'E';
	else if (sx > dx)
		d1 = 'W';
	if (sy < dy)
		d2 = 'N';
	else if (sy > dy)
		d2 = 'S';
	while (cin >> d && (d1 != '0' || d2 != '0'))
	{
		if (d == d1)
		{
			switch (d1)
			{
			case 'E':
				cx++;
				break;
			case 'W':
				cx--;
				break;
			}
			if (cx == dx)
				d1 = '0';
		}
		else if (d == d2)
		{
			switch (d2)
			{
			case 'N':
				cy++;
				break;
			case 'S':
				cy--;
				break;
			}
			if (cy == dy)
				d2 = '0';
		}
		time++;
	}
	cout << (d1 == '0' && d2 == '0' ? time : -1);
	return 0;
}