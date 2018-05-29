#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length();
	for (size_t i = 0; i < n; i++)
	{
		if (s1[i] != s2[n - i - 1])
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}