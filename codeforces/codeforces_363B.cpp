#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int n, k, input, sum = 0, currentSum, answer = 1;
	queue<int> data;
	cin >> n >> k;
	for (size_t i = 0; i < k; i++)
	{
		cin >> input;
		sum += input;
		data.push(input);
	}
	n -= k;
	currentSum = sum;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		currentSum -= data.front();
		currentSum += input;
		data.push(input);
		data.pop();
		sum = min(sum, currentSum);
		if (sum == currentSum)
			answer = i + 2;
	}
	cout << answer;
	return 0;
}