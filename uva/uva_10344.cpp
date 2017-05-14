#include <iostream>
#include <vector>
using namespace std;

// bijective means that any value from set 1 can map to any value from set 2
// generate all possible mappings of the five input elements (a)
// generate all permutations of o
// check if possible

int a[5], selected[5];
int permutationsSize;
char o[4];
bool solved;
vector<int> currentPermutation;
vector<vector<int>> permutations;

void permutationsOfFive(int n = 0)
{
	if (n == 5)
	{
		permutations.push_back(currentPermutation);
		return;
	}
	for (size_t i = 0; i < 5; i++)
	{
		if (!selected[i])
		{
			currentPermutation.push_back(i);
			selected[i] = true;
			permutationsOfFive(n + 1);
			currentPermutation.pop_back();
			selected[i] = false;
		}
	}
}

void twoThreeOutOfFive(int n = 0)
{
	if (n == 4)
	{
		for (size_t i = 0; i < permutationsSize; i++)
		{
			int solution;
			switch (o[0])
			{
			case '+':
				solution = a[permutations[i][0]] + a[permutations[i][1]];
				break;
			case '-':
				solution = a[permutations[i][0]] - a[permutations[i][1]];
				break;
			case '*':
				solution = a[permutations[i][0]] * a[permutations[i][1]];
				break;
			}
			switch (o[1])
			{
			case '+':
				solution += a[permutations[i][2]];
				break;
			case '-':
				solution -= a[permutations[i][2]];
				break;
			case '*':
				solution *= a[permutations[i][2]];
				break;
			}
			switch (o[2])
			{
			case '+':
				solution += a[permutations[i][3]];
				break;
			case '-':
				solution -= a[permutations[i][3]];
				break;
			case '*':
				solution *= a[permutations[i][3]];
				break;
			}
			switch (o[3])
			{
			case '+':
				solution += a[permutations[i][4]];
				break;
			case '-':
				solution -= a[permutations[i][4]];
				break;
			case '*':
				solution *= a[permutations[i][4]];
				break;
			}
			if (solution == 23)
			{
				solved = true;
				return;
			}
		}
		return;
	}
	o[n] = '+';
	twoThreeOutOfFive(n + 1);
	if (solved)
		return;
	o[n] = '-';
	twoThreeOutOfFive(n + 1);
	if (solved)
		return;
	o[n] = '*';
	twoThreeOutOfFive(n + 1);
	if (solved)
		return;
}

int main()
{
	permutationsOfFive();
	permutationsSize = permutations.size();
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4])
	{
		solved = false;
		if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0)
			break;
		twoThreeOutOfFive();
		if (solved)
			cout << "Possible" << endl;
		else
			cout << "Impossible" << endl;
	}
	return 0;
}