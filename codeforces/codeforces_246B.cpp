#include <iostream>
using namespace std;

long long n, input, sum;

int main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		sum += input;
	}
	if (sum % n == 0)
		cout << n;
	else
		cout << n - 1;
	return 0;
}
