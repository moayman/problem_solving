#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int numberOfSolutions = 0;
vector<bool> col(15), d1(29), d2(29);
vector<pair<int, int>> currentSolution;
vector <vector<pair<int, int>>> solutions;

void sultanSuccessors(int row)
{
	if (row == 8)
	{
		numberOfSolutions++;
		solutions.push_back(vector < pair<int, int>>(currentSolution));
		return;
	}
	for (size_t i = 0; i < 8; i++)
	{
		if (!col[i] && !d1[row + i] && !d2[row - i + 8 - 1])
		{
			col[i] = true;
			d1[row + i] = true;
			d2[row - i + 8 - 1] = true;
			currentSolution.push_back(pair<int, int>(row, i));
			sultanSuccessors(row + 1);
			currentSolution.pop_back();
			col[i] = false;
			d1[row + i] = false;
			d2[row - i + 8 - 1] = false;
		}
	}
}

int main()
{
	sultanSuccessors(0);
	int k;
	bool endline = false;
	cin >> k;
	for (size_t a = 0; a < k; a++)
	{
		int board[8][8] = { 0 };
		int input;
		for (size_t i = 0; i < 8; i++)
		{
			for (size_t j = 0; j < 8; j++)
			{
				cin >> input;
				board[i][j] = input;
			}
		}
		int maximum = INT_MIN;
		for (size_t i = 0; i < solutions.size(); i++)
		{
			int solution = 0;
			for (size_t j = 0; j < 8; j++)
			{
				solution += board[solutions[i][j].first][solutions[i][j].second];
			}
			maximum = solution > maximum ? solution : maximum;
		}
		cout.width(5);
		cout << std::right << maximum << endl;
	}
	return 0;
}