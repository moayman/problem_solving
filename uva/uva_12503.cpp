#include <iostream>
#include <string>
using namespace std;

#define RIGHT 0
#define LEFT 1

int main()
{
	size_t T, n;
	string input;
	int ith;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		cin >> n;
		int p = 0;
		int moves[100] = { 0 };
		for (size_t j = 0; j < n; j++)
		{
			cin >> input;
			if (input == "LEFT")
			{
				moves[j] = LEFT;
				--p;
			}
			else if (input == "RIGHT")
			{
				moves[j] = RIGHT;
				++p;
			}
			else
			{
				cin >> input >> ith;
				moves[j] = moves[ith - 1];
				if (moves[j] == LEFT)
				{
					--p;
				}
				else if (moves[j] == RIGHT)
				{
					++p;
				}
			}
		}
		cout << p << endl;
	}
	return 0;
}