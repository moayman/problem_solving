#include <iostream>
#include <map>
using namespace std;

long long n, input, minimum = 0x7FFFFFFFFFFFFFFF, leastInputIndex = 0;
map<long long, long long> data;

int main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		data[input]++;
		if (minimum > input)
		{
			leastInputIndex = i;
			minimum = input;
		}
	}
	if (data.begin()->second > 1)
		cout << "Still Rozdil";
	else
		cout << leastInputIndex + 1;
	return 0;
}