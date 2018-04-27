#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, k, input, lastInput, index;

int main()
{
	cin >> n >> k;
	cin >> lastInput;
	index = 0;
	for (size_t i = 1; i < n; i++)
	{
		cin >> input;
		if (input != lastInput)
		{
			index = i;
			lastInput = input;
		}
	}
	if (index == 0)
		cout << 0;
	else if (k >= index + 1)
		cout << index;
	else
		cout << -1;
	return 0;
}
