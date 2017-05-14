#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, inputSize, numberOfSubstrings;
	string input;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		string sub;
		inputSize = input.size();
		for (size_t j = 0; j < inputSize; j++)
		{
			sub += input[j];
			if (inputSize % (j + 1) == 0)
			{
				string toTest;
				numberOfSubstrings = inputSize / (j + 1);
				for (size_t k = 0; k < numberOfSubstrings; k++)
				{
					toTest += sub;
				}
				if (toTest == input)
				{
					if (i)
						cout << endl;
					cout << sub.size() << endl;
					break;
				}
			}
		}
	}
	return 0;
}