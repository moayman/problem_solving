#include <iostream>
using namespace std;

long long n, m, data[100000];

int main()
{
	cin >> n >> m;
	for (size_t i = 0; i < m; i++)
		cin >> data[i];
	long long current = 1;
	long long answer = 0;
	for (size_t i = 0; i < m; i++)
	{
		if (data[i] != current)
		{
			if (data[i] > current)
				answer += data[i] - current;
			else
				answer += n - current + data[i];
			current = data[i];
		}
	}
	cout << answer;
	return 0;
}