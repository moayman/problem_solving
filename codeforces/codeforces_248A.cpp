#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	map<int, int> left, right;
	int input, n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		left[input]++;
		cin >> input;
		right[input]++;
	}
	cout << (left.size() == 1 ? 0 : min(left.begin()->second, left.rbegin()->second)) + (right.size() == 1 ? 0 : min(right.begin()->second, right.rbegin()->second));
	return 0;
}