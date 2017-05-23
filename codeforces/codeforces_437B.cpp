#include <iostream>
#include <set>
#include <vector>
using namespace std;

int getLowBit(int num)
{
	int bitNum = 0;
	while (!(num & 1))
	{
		bitNum++;
		num >>= 1;
	}
	return 1 << bitNum;
}

void main()
{
	int sum, limit, lowbit;
	set<pair<int, int>> data;
	vector<int> answer;
	cin >> sum >> limit;
	for (size_t i = 1; i <= limit; i++)
	{
		data.insert(pair<int, int>(getLowBit(i), i));
	}
	set<pair<int, int>>::reverse_iterator dataIterator = data.rbegin();
	while (sum != 0 && dataIterator != data.rend())
	{
		if (sum >= dataIterator->first)
		{
			sum -= dataIterator->first;
			answer.push_back(dataIterator->second);
		}
		dataIterator++;
	}
	if (sum == 0)
	{
		cout << answer.size() << endl;
		for (size_t i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << " ";
		}
	}
	else
	{
		cout << -1;
	}
}
