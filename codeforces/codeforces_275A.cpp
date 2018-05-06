#include <iostream>
using namespace std;

bool grid[3][3] = { { true, true, true }, { true, true, true }, { true, true, true } };
int input;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &input);
			if (input != 0 && input % 2 != 0)
			{
				grid[i][j] = !grid[i][j];
				if (i - 1 > -1)
					grid[i - 1][j] = !grid[i - 1][j];
				if (j - 1 > -1)
					grid[i][j - 1] = !grid[i][j - 1];
				if (i + 1 < 3)
					grid[i + 1][j] = !grid[i + 1][j];
				if (j + 1 < 3)
					grid[i][j + 1] = !grid[i][j + 1];
			}
		}
	}
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
	return 0;
}