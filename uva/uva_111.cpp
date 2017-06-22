#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

int position[22], data[22], dp[22], n, input, answer;

int main()
{
	string line;
	while (getline(cin, line))
	{
		stringstream ss(line);
		if (line.length() < 3)
		{
			ss >> n;
			getline(cin, line);
			stringstream sss(line);
			for (size_t i = 1; i <= n; i++)
			{
				sss >> input;
				position[i] = input;
			}
		}
		else
		{
			memset(dp, -1, sizeof dp);
			answer = 1;
			dp[n - 1] = 1;
			for (size_t i = 1; i <= n; i++)
			{
				ss >> input;
				data[input - 1] = i;
			}
			for (int i = n - 1; i > -1; i--)
			{
				int currentAnswer = 1, toAdd = 0;
				for (int j = i + 1; j < n; j++)
				{
					if (position[data[i]] < position[data[j]])
					{
						if (dp[j] > toAdd)
							toAdd = dp[j];
					}
				}
				dp[i] = currentAnswer + toAdd;
				if (dp[i] > answer)
					answer = dp[i];
			}
			cout << answer << endl;
		}
	}
	return 0;
}
