#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << n;
	for (size_t i = 1; i < n; i++)
		cout << ' ' << i;
	return 0;
}