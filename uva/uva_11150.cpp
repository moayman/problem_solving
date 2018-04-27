#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, output;

int main()
{
	while (cin >> n)
	{
		output = n;					// initial non empty cola
		++n;						// take empty bottle from friend
		while (n / 3)
		{
			output += n / 3;		// add bottles that can be replaced
			n = n % 3 + n / 3;		// n = n / 3 + the remaining empty bottles if any
		}
		cout << output << "\n";
	}
	return 0;
}
