#include <iostream>
using namespace std;

int data[3]; // 0 = 25, 1 = 50, 2 = 100

int main()
{
	int n, input;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		switch (input)
		{
		case 25:
			data[0]++;
			break;
		case 50:
			if (data[0] > 0)
			{
				data[0]--;
			}
			else
			{
				cout << "NO";
				return 0;
			}
			data[1]++;
			break;
		case 100:
			if (data[1] > 0 && data[0] > 0)
			{
				data[1]--;
				data[0]--;
			}
			else if (data[0] > 2)
			{
				data[0] -= 3;
			}
			else
			{
				cout << "NO";
				return 0;
			}
			data[2]++;
			break;
		}
	}
	cout << "YES";
	return 0;
}