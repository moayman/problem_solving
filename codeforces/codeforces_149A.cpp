#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n, input, answer = 0;
	multiset<int> data;
	cin >> n;
	for (size_t i = 0; i < 12; i++)
	{
		cin >> input;
		data.insert(input);
	}
	for (auto it = data.rbegin(); it != data.rend() && n > 0; it++)
	{
		answer++;
		n -= *it;
	}
	if (n > 0)
		cout << -1;
	else
		cout << answer;
	return 0;
}