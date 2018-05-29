#include <iostream>
using namespace std;

int main()
{
	int n, data[7];
	cin >> n >> data[0] >> data[1] >> data[2] >> data[3] >> data[4] >> data[5] >> data[6];
	while (n > 0)
	{
		for (size_t i = 0; i < 7; i++)
		{
			n -= data[i];
			if (n < 1)
			{
				cout << i + 1;
				return 0;
			}
		}
	}
	return 0;
}