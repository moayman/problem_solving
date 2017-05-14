#include <iostream>
using namespace std;

void main()
{
	// O(n)
	// A new group is created whenever two magnets are not the same
	size_t n, groups = 1;
	int in, last_in;
	cin >> n >> last_in;
	for (size_t i = 1; i < n; i++)
	{
		cin >> in;
		if (last_in != in)
			groups++;
		last_in = in;
	}
	cout << groups;
}