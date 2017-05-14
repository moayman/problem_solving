#include <iostream>
using namespace std;
// tested from 1 to 50 nothing goes to infinity to print -1
bool isSquare(unsigned int number)
{
	unsigned int num = 1, mult;
	while (true)
	{
		mult = num*num;
		if (mult == number)
			return true;
		else if (mult > number)
			return false;
		num++;
	}
}

int main()
{
	size_t T, N;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		cin >> N;
		unsigned int topOfPegs[50] = { 0 };
		unsigned int currentBall = 1;
		bool done = false, consumedABall = false;
		while (!done)
		{
			consumedABall = false;
			for (size_t i = 0; i < N; i++)
			{
				if (topOfPegs[i] == 0 || isSquare(currentBall + topOfPegs[i]))
				{
					topOfPegs[i] = currentBall++;
					consumedABall = true;
					break;
				}
			}
			if (!consumedABall)
			{
				done = true;
			}
		}
		cout << currentBall - 1 << endl;
	}
	return 0;
}