#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n, h, m, hh, mm, answer = 1, currentAnswer = 1;
	cin >> n >> h >> m;
	for (size_t i = 1; i < n; i++)
	{
		cin >> hh >> mm;
		if (hh == h && mm == m)
			currentAnswer++;
		else
		{
			answer = max(answer, currentAnswer);
			currentAnswer = 1;
		}
		h = hh;
		m = mm;
	}
	cout << max(answer, currentAnswer);
	return 0;
}