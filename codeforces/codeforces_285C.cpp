#include <iostream>
#include <math.h>
#include <set>
using namespace std;

multiset<long long> data;
long long n, input;
unsigned long long answer;

int main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		data.insert(input);
	}
	for (auto it = data.rbegin(); it != data.rend(); it++)
	{
		if (*it != n)
		{
			answer += abs(n - *it);
		}
		n--;
	}
	cout << answer;
	return 0;
}
