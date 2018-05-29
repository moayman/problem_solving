#include <iostream>
using namespace std;

int main()
{
	int input, n, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n6 = 0;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		if (input == 5 || input == 7)
		{
			cout << -1;
			return 0;
		}
		switch (input)
		{
		case 1:
			n1++;
			break;
		case 2:
			n2++;
			break;
		case 3:
			n3++;
			break;
		case 4:
			n4++;
			break;
		case 6:
			n6++;
			break;
		}
	}
	n /= 3;
	if (n1 == n && (n2 + n3 == n) && (n4 + n6 == n) && n6 >= n3)
	{
		for (size_t i = 0; i < n; i++)
		{
			cout << 1 << ' ';
			if (n2)
			{
				cout << 2 << ' ';
				n2--;
				if (n4)
				{
					cout << 4 << endl;
					n4--;
				}
				else if (n6)
				{
					cout << 6 << endl;
					n6--;
				}
			}
			else if (n3)
			{
				cout << 3 << ' ';
				n3--;
				if (n6)
				{
					cout << 6 << endl;
					n6--;
				}
			}
		}
	}
	else
	{
		cout << -1;
	}
	return 0;
}