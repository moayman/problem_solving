#include <iostream>
#include <set>
using namespace std;

// solution is so bad

int main()
{
	int n, input;
	while (cin >> n)
	{
		if (n == 0)
			break;
		multiset<int> data;
		int numberOfZeros = 0, firstInteger1 = 0, secondInteger1 = 0, firstInteger2 = 0, secondInteger2 = 0;
		for (size_t i = 0; i < n; i++)
		{
			cin >> input;
			if (!input)
				numberOfZeros++;
			else
				data.insert(input);
		}
		bool insertZeros = false;
		while (numberOfZeros || data.size())
		{
			if (insertZeros && numberOfZeros != 0)
			{
				if (numberOfZeros % 2 == 0)
				{
					numberOfZeros /= 2;
					for (size_t i = 0; i < numberOfZeros; i++)
					{
						firstInteger1 *= 10; secondInteger1 *= 10;
						firstInteger2 *= 10; secondInteger2 *= 10;
					}
				}
				else
				{
					numberOfZeros /= 2;
					for (size_t i = 0; i < numberOfZeros; i++)
					{
						firstInteger1 *= 10;
						secondInteger2 *= 10;
					}
					numberOfZeros++;
					for (size_t i = 0; i < numberOfZeros; i++)
					{
						secondInteger1 *= 10;
						firstInteger2 *= 10;
					}
				}
				numberOfZeros = 0;
			}
			if (data.size() != 0)
			{
				firstInteger1 *= 10; firstInteger1 += *data.begin();
				firstInteger2 *= 10; firstInteger2 += *data.begin();
				data.erase(data.begin());
			}
			if (data.size() != 0)
			{
				secondInteger1 *= 10; secondInteger1 += *data.begin();
				secondInteger2 *= 10; secondInteger2 += *data.begin();
				data.erase(data.begin());
			}
			insertZeros = true;
		}
		cout << ((firstInteger1 + secondInteger1) < (firstInteger2 + secondInteger2) ? (firstInteger1 + secondInteger1) : (firstInteger2 + secondInteger2)) << endl;
	}
	return 0;
}