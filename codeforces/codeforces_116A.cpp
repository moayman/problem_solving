#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, input, currentPassengers = 0, answer = 0;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		currentPassengers -= input;
		answer = max(currentPassengers, answer);
		cin >> input;
		currentPassengers += input;
		answer = max(currentPassengers, answer);
	}
	cout << answer;
	return 0;
}