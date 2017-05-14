#include <iostream>
#include <string>
using namespace std;

int main()
{
	// There must be a better way
	size_t t;
	long long n;
	string s;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		cin >> n;
		s = to_string(((((n * 63) + 7492) * 5) - 498));
		if (s.length() > 1)
			cout << s[s.length() - 2] << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}