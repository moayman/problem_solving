#include <iostream>
#include <deque>
#include <string>
using namespace std;

#define PUSH_FRONT true
#define PUSH_BACK false

int main()
{
	string line;
	char c;
	size_t lineSize, outputSize;
	while (getline(cin, line))
	{
		deque<char> output;
		deque<char>::iterator iterator;
		lineSize = line.size();
		bool pushPosition = PUSH_BACK;
		for (size_t i = 0; i < lineSize; i++)
		{
			c = line[i];
			switch (c)
			{
			case '[':
				pushPosition = PUSH_FRONT;
				iterator = output.begin();
				break;
			case ']':
				pushPosition = PUSH_BACK;
				iterator = output.begin();
				break;
			default:
				if (pushPosition == PUSH_BACK)
					output.push_back(c);
				else if (pushPosition == PUSH_FRONT)
				{
					iterator = output.insert(iterator, c);
					iterator++;
				}
				break;
			}
		}
		outputSize = output.size();
		for (auto it : output)
			cout << it;
		cout << endl;
	}
	return 0;
}