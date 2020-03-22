#include <iostream>
#include <vector>
using namespace std;

int t, n, m, myscore, input, data;

int main()
{
	cin >> t;
	for (size_t q = 0; q < t; q++)
	{
		cin >> n >> m >> myscore;
		data = 0;
		for (size_t i = 1; i < n; i++)
		{
			cin >> input;
			data += input;
		}
		if (m - myscore < data)
			cout << m << endl;
		else
			cout << data + myscore << endl;
	}
	return 0;
}
