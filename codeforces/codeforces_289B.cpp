#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int n, m, d, s, input;
vector<int> data;

int main()
{
	cin >> n >> m >> d;
	s = n * m;
	for (size_t i = 0; i < s; i++)
	{
		cin >> input;
		data.push_back(input);
	}
	sort(data.begin(), data.end());
	int mid = s / 2;
	int answer = 0;
	for (size_t i = 0; i < s; i++)
	{
		if ((data[mid] - data[i]) % d != 0)
		{
			cout << -1;
			return 0;
		}
		answer += abs(data[mid] - data[i]) / d;
	}
	cout << answer;
	return 0;
}
