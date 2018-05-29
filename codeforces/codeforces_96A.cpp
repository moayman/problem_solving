#include <iostream>
using namespace std;

int main()
{
	int count = 1;
	char lastInput, input;
	cin >> lastInput;
	while (cin >> input)
	{
		if (input == lastInput)
			count++;
		else
		{
			lastInput = input;
			count = 1;
		}
		if (count == 7)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}