#include <iostream>
#include <limits.h>
#include <map>
using namespace std;

#define max(a,b) a > b ? a : b

int main()
{
	size_t N;
	while (cin >> N)
	{
		map<unsigned int, unsigned int> data;
		unsigned int input, sum, ans1, ans2, diff = UINT_MAX;
		for (size_t i = 0; i < N; i++)
		{
			cin >> input;
			data[input]++;
		}
		cin >> sum;
		for (map<unsigned int, unsigned int>::iterator it = data.begin(); it != data.end(); it++)
		{
			unsigned int possibleAns2 = it->first, possibleAns1 = sum - it->first;
			if (data.find(possibleAns1) != data.end())
			{
				if (possibleAns1 == it->first)
				{
					if (it->second > 1)
					{
						ans1 = possibleAns1;
						ans2 = ans1;
						break;
					}
				}
				else
				{
					possibleAns2 = max(possibleAns1, possibleAns2);
					possibleAns1 = sum - possibleAns2;
					if (possibleAns2 - possibleAns1 < diff)
					{
						diff = possibleAns2 - possibleAns1;
						ans2 = possibleAns2;
						ans1 = possibleAns1;
					}

				}
			}
		}
		cout << "Peter should buy books whose prices are " << ans1 << " and " << ans2 << "." << endl << endl;
	}
	return 0;
}