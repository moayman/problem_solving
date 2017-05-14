#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

int main()
{
	unordered_map<char, char> brackets = { pair<char, char>('(', ')'), pair<char, char>('[', ']') };
	size_t n, inputSize;
	string input;
	cin >> n;
	cin.ignore();
	for (size_t i = 0; i < n; i++)
	{
		stack<char> data;
		getline(cin, input);
		inputSize = input.size();
		for (size_t j = 0; j < inputSize; j++)
		{
			if (input[j] == '(')
			{
				data.push('(');
				continue;
			}
			if (input[j] == '[')
			{
				data.push('[');
				continue;
			}
			if (data.size() && brackets[data.top()] == input[j])
				data.pop();
			else
			{
				cout << "No" << endl;
				goto DONE;
			}
		}
		// must check if there is more unprocessed data ((()
		if (data.size())
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	DONE:
		;
	}
	return 0;
}