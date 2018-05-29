#include <iostream>
using namespace std;

int main()
{
	int n, n100 = 0, n200 = 0, input;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		if (input == 100)
			n100++;
		else
			n200++;
	}
	if (n200 % 2 == 0 && n100 % 2 == 0)
		cout << "YES";
	else if (n200 > 0 && n100 > 0 && ((n200 * 2) + n100) % 2 == 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}