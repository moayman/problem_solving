#include <iostream>
using namespace std;

int main()
{
	char c;
	while (cin >> c)
	{
		if (c == '.')
			cout << 0;
		else if (c == '-')
		{
			if (cin >> c)
			{
				if (c == '.')
					cout << 1;
				else if (c == '-')
					cout << 2;
			}
		}
	}
	return 0;
}