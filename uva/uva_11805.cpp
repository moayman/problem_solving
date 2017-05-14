#include <iostream>
using namespace std;

int main()
{
	int N, T, K, P, out;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		cin >> N >> K >> P;
		out = (P + K) % N;
		cout << "Case " << i + 1 << ": " << ((out == 0) ? N : out) << endl;
	}
	return 0;
}