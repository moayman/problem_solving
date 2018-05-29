#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> data;
	int input, answer = 0;
	for (size_t i = 0; i < 4; i++)
	{
		cin >> input;
		data[input]++;
		if (data[input] > 1)
			answer++;
	}
	cout << answer;
	return 0;
}