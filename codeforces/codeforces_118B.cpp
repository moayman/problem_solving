#include <iostream>
using namespace std;

void main()
{
	int n, m, p, spaces, pre_post;
	bool increment = true;
	cin >> n;
	m = n * 2 + 1;
	for (int i = m, toprint = 1; i > 0; i--)
	{
		spaces = (m - toprint) / 2;
		for (int j = 0; j < spaces; j++)
		{
			cout << "  ";
		}
		pre_post = n - spaces;
		for (int j = 0; j < pre_post; j++)
		{
			cout << j << " ";
		}
		cout << pre_post;
		for (int j = pre_post - 1; j > -1; j--)
		{
			cout << " " << j;
		}
		cout << endl;
		if (pre_post == n)
			increment = false;
		if (increment)
			toprint += 2;
		else
			toprint -= 2;
	}
}