#include <iostream>
using namespace std;

int main()
{
	int n, input;
	while (cin >> n)
	{
		if (n == 0)
			break;
		int maximumWinningStreak = 0, currentStreak = 0;
		bool losingStreak = true;
		for (size_t i = 0; i < n; i++)
		{
			cin >> input;
			currentStreak += input;
			if (input > 0)
				losingStreak = false;
			else if (currentStreak < 0)
				currentStreak = 0;
			maximumWinningStreak = maximumWinningStreak > currentStreak ? maximumWinningStreak : currentStreak;
		}
		if (losingStreak)
			cout << "Losing streak." << endl;
		else
		{
			cout << "The maximum winning streak is " << maximumWinningStreak << "." << endl;
		}
	}
	return 0;
}
