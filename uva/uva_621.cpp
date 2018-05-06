#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, l;
string s;

int main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> s;
		l = s.length();
		if (l > 1 && s[l - 1] == '5' && s[l - 2] == '3')
			cout << "-\n";
		else if (l > 1 && s[0] == '9' && s[l - 1] == '4')
			cout << "*\n";
		else if (l > 2 && s[0] == '1'  && s[1] == '9' && s[2] == '0')
			cout << "?\n";
		else if (l == 1 && s[0] == '1' || l == 1 && s[0] == '4' || l == 2 && s[0] == '7' && s[1] == '8')
			cout << "+\n";
		else
			cout << "?\n";
	}
	return 0;
}
