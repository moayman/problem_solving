#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int input[4], d, answer = 0;

int main()
{
	cin >> input[0] >> input[1] >> input[2] >> input[3] >> d;
	d++;
	for (size_t j = 1; j < d; j++)
	{
		if (j % input[0] == 0 ||
			j % input[1] == 0 ||
			j % input[2] == 0 ||
			j % input[3] == 0)
			answer++;
	}
	cout << answer;
	return 0;
}