#include <iostream>
#include <set>
#include <string>
using namespace std;

int r, c;
bool col[15], d1[29], d2[29]; // diagonals i+j, i-j+n-1
string currentSolution("00000000"); // index=col, value=row
set <string> solutions;

void eightQueensChessProblem(int row)
{
	if (row == 8)
	{
		solutions.insert(currentSolution);
		return;
	}
	if (row == r)
	{
		eightQueensChessProblem(row + 1);
		return;
	}
	for (size_t i = 0; i < 8; i++)
	{
		if (!col[i] && !d1[row + i] && !d2[row - i + 8 - 1])
		{
			col[i] = true;
			d1[row + i] = true;
			d2[row - i + 8 - 1] = true;
			currentSolution[i] = row + '1';
			eightQueensChessProblem(row + 1);
			col[i] = false;
			d1[row + i] = false;
			d2[row - i + 8 - 1] = false;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (size_t a = 0; a < T; a++)
	{
		solutions.clear();
		cin >> r >> c;
		r--; c--;
		col[c] = true;
		d1[r + c] = true;
		d2[r - c + 8 - 1] = true;
		currentSolution[c] = r + '1';
		eightQueensChessProblem(0);
		col[c] = false;
		d1[r + c] = false;
		d2[r - c + 8 - 1] = false;
		if (a)
			cout << endl;
		cout << "SOLN       COLUMN" << endl << " #      1 2 3 4 5 6 7 8" << endl << endl;
		int i = 1;
		for (auto it : solutions)
		{
			cout.width(2);
			cout << std::right << i << "      ";
			for (size_t j = 0; j < 8; j++)
			{
				cout << it[j];
				if (j != 7)
					cout << " ";
			}
			cout << endl;
			i++;
		}
	}
	return 0;
}