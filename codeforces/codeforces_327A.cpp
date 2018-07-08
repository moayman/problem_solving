#include <iostream>
#include <algorithm>
using namespace std;

int data[101];

int main()
{
	int n, input;
	cin >> n;
	cin >> input;
	data[1] = (input == 1 ? 1 : 0);
	for (size_t i = 2; i < n + 1; i++)
	{
		cin >> input;
		data[i] = data[i - 1] + (input == 1 ? 1 : 0);
	}
	n++;
	int answer = -1;
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			answer = max(answer, (j - i + 1) - (data[j] - data[i - 1]) + data[i - 1] + (data[n - 1] - data[j]));
		}
	}
	cout << answer;
	return 0;
}