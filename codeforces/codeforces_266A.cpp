#include <iostream>
using namespace std;

void main()
{
	// O(n)
	// Need to have no repetition of any character
	// Increment out whenever last letter is equal to the input
	char in, last_in;
	size_t n, out = 0;
	cin >> n >> last_in;
	for (size_t i = 1; i < n; i++)
	{
		cin >> in;
		if (last_in == in)
			++out;
		else
			last_in = in;
	}
	cout << out;
}