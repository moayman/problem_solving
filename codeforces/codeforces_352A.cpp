#include <iostream>
#include <algorithm>
using namespace std;

// if we got zeros and fives then the number fives must be a multiple of nine and the zeros are to be put as the right most digits
// if we don't have zeros then there is no answer == -1
// else the max number is 0
long long n, data[10000], countOf5 = 0, countOf0 = 0;

int main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> data[i];
		if (data[i] == 0)
			countOf0++;
		else
			countOf5++;
	}
	if (countOf5 > 8 && countOf0 > 0)
	{
		countOf5 = (countOf5 / 9) * 9;
		for (size_t i = 0; i < countOf5; i++)
		{
			cout << '5';
		}
		for (size_t i = 0; i < countOf0; i++)
		{
			cout << '0';
		}
	}
	else
		cout << (countOf0 == 0 ? -1 : 0);
	return 0;
}