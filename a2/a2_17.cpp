#include <iostream>
using namespace std;

int a2_17()
{
	size_t T, N;
	unsigned long long in, K;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		unsigned long long out = 0;
		cin >> N >> K;
		for (size_t j = 0; j < N; j++)
		{
			cin >> in;
			out += in / K;
		}
		cout << out << endl;
	}
	return 0;
}