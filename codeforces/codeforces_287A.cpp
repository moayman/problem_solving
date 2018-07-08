#include <iostream>
using namespace std;

int main()
{
	char data[4][4];
	char c;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cin >> data[i][j];
		}
	}
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			int nB = 0, nW = 0;
			for (size_t a = i; a < i + 2; a++)
			{
				for (size_t b = j; b < j + 2; b++)
				{
					if (data[a][b] == '.')
						nB++;
					else
						nW++;
				}
			}
			if (nB > 2 || nW > 2)
			{
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}