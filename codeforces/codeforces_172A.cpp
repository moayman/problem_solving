#include <iostream>
#include <string>
using namespace std;

int n, l;
string numbers[30000];

int main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
		cin >> numbers[i];
	l = numbers[0].length();
	for (size_t i = 0; i < l; i++)
	{
		for (size_t j = 1; j < n; j++)
		{
			if (numbers[j][i] != numbers[j - 1][i])
			{
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}
