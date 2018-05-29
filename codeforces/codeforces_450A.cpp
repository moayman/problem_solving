#include <iostream>
using namespace std;

int main()
{
	int n, m, input, maximum = 0, answer = 0, value;
	cin >> n >> m;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		value = (input / m) + (input % m != 0);
		if (value >= maximum)
		{
			maximum = value;
			answer = i + 1;
		}
	}
	cout << (answer == 0 ? n : answer);
	return 0;
}