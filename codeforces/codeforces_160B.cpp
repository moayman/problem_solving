#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s1 = "", s2 = "";
	char c;
	int n, a, b;
	cin >> n;
	a = 0; b = (2 * n) - 1;
	for (size_t i = 0; i < n; i++)
	{
		cin >> c;
		s1 += c;
	}
	for (size_t i = 0; i < n; i++)
	{
		cin >> c;
		s2 += c;
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	int bigger = -1;
	for (size_t i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			if (bigger == -1)
			{
				bigger = (s1[i] > s2[i] ? 1 : 0);
			}
			else if (bigger != (s1[i] > s2[i] ? 1 : 0))
			{
				cout << "NO";
				return 0;
			}

		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	cout << (bigger == -1 ? "NO" : "YES");
	return 0;
}