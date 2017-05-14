#include <iostream>
#include <string>
using namespace std;

int N, H;
string hamming;

void hammingDistance(int n = 0, int h = 0)
{
	if (n == N)
	{
		if (h == H)
		{
			cout << hamming << endl;
		}
		return;
	}
	hamming.push_back('0');
	hammingDistance(n + 1, h);
	hamming.pop_back();
	if (h != H)
	{
		hamming.push_back('1');
		hammingDistance(n + 1, h + 1);
		hamming.pop_back();
	}
}

int main()
{
	size_t T;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		if (i)
			cout << endl;
		hamming = "";
		cin >> N >> H;
		hammingDistance();
	}
	return 0;
}