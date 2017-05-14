#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> strings = { "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999" };

int main()
{
	size_t T;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		int f, a;
		cin >> a >> f;
		for (int j = 0; j < f; j++)
		{
			for (int k = 0; k < a; k++)
			{
				cout << strings[k] << endl;
			}
			for (int k = a - 2; k > -1; k--)
			{
				cout << strings[k] << endl;
			}
			if (j != f - 1)
				cout << endl;
		}
		if (i != T - 1)
			cout << endl;
	}
	return 0;
}