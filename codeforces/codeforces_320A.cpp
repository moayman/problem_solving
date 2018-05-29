#include <iostream>
#include <algorithm>
using namespace std;

#define start 0
#define one 1
#define four 2
#define secondfour 3

int main()
{
	char c;
	int currentState = start;
	while (cin >> c)
	{
		switch (c)
		{
		case '1':
			currentState = one;
			break;
		case '4':
			switch (currentState)
			{
			case one:
				currentState = four;
				break;
			case four:
				currentState = secondfour;
				break;
			default:
				cout << "NO";
				return 0;
			}
			break;
		default:
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}