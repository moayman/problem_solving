#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long answer = -1, data[5][5];
bool inLine[5];

long long getAnswer(string s)
{
	long long currentAnswer = 0;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = i + 1; j < 5; j += 2)
		{
			int i1 = s[j - 1] - '1', i2 = s[j] - '1';
			currentAnswer += data[i1][i2] + data[i2][i1];
		}
	}
	return currentAnswer;
}

void solve(int index = 0, string s = "")
{
	if (index == 5)
	{
		answer = max(answer, getAnswer(s));
		return;
	}
	for (size_t i = 0; i < 5; i++)
	{
		if (!inLine[i])
		{
			inLine[i] = true;
			solve(index + 1, s + to_string(i + 1));
			inLine[i] = false;
		}
	}
}

int main()
{
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			cin >> data[i][j];
		}
	}
	solve();
	cout << answer;
	return 0;
}