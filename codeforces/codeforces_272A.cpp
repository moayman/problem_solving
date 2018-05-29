#include <iostream>
using namespace std;

int main()
{
	int n, input, fingers = 0, answer = 0;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		fingers += input;
	}
	++n;
	for (size_t i = 1; i < 6; i++)
	{
		if ((fingers + i) % n != 1)
			answer++;
	}
	cout << answer;
	return 0;
}