#include <iostream>
#include <map>
using namespace std;

void main()
{
	unsigned int N[50], M[50], num;
	map<unsigned int, unsigned int> data;
	size_t n, m;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> N[i];
	}
	cin >> m;
	for (size_t i = 0; i < m; i++)
	{
		cin >> M[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			num = M[j] / N[i];
			if (num*N[i] == M[j])
				data[num]++;
		}
	}
	cout << data.rbegin()->second;
}