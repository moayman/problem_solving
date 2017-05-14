#include <iostream>
#include <vector>
using namespace std;

int n, numberOfSolutions;
bool col[15], d1[29], d2[29];
bool bad[15][15];

void anotherNQueensProblem(int row)
{
	if (row == n)
	{
		numberOfSolutions++;
		return;
	}
	for (size_t i = 0; i < n; i++)
	{
		if (!col[i] && !d1[row + i] && !d2[row - i + n - 1] && !bad[row][i])
		{
			col[i] = true;
			d1[row + i] = true;
			d2[row - i + n - 1] = true;
			anotherNQueensProblem(row + 1);
			col[i] = false;
			d1[row + i] = false;
			d2[row - i + n - 1] = false;
		}
	}
}

int main()
{
	int T = 0;
	char input;
	while (cin >> n)
	{
		if (n == 0)
			break;
		numberOfSolutions = 0;
		T++;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				bad[i][j] = false;
				cin >> input;
				if (input == '*')
					bad[i][j] = true;
			}
		}
		anotherNQueensProblem(0);
		cout << "Case " << T << ": " << numberOfSolutions << endl;
	}
	return 0;
}