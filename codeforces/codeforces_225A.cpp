#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, top, bottom;
int r[100], l[100], br[100], bl[100];

int main()
{
	cin >> n >> top;
	bottom = 7 - top;
	for (size_t i = 0; i < n; i++)
	{
		cin >> r[i] >> l[i];
		if (r[i] + l[i] == 7)
		{
			cout << "NO";
			return 0;
		}
		br[i] = 7 - r[i]; bl[i] = 7 - l[i];
		bool faces[7] = { true, true, true, true, true, true, true };
		faces[r[i]] = false;
		faces[l[i]] = false;
		faces[br[i]] = false;
		faces[bl[i]] = false;
		faces[bottom] = false;
		int count = 0;
		for (size_t i = 1; i < 7; i++)
		{
			if (faces[i])
			{
				count++;
				bottom = 7 - i;
			}
		}
		if (count != 1)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
