#include <iostream>
using namespace std;

void main()
{
	// I believe there is a better way
	unsigned long long a, b, renewed, out = 0;
	cin >> a >> b;
	out += a;
	do
	{
		renewed = a / b;
		out += renewed;
		a = (a % b) + renewed;
	} while (renewed);
	cout << out;
}