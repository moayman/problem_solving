#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;

int main()
{
	int n, m, input, maxAnswer = 0, minAnswer = 0;
	multiset<int> dataAsc;
	multiset<int, greater<int>> dataDsc;
	cin >> n >> m;
	for (size_t i = 0; i < m; i++)
	{
		cin >> input;
		dataAsc.insert(input);
		dataDsc.insert(input);
	}
	for (size_t i = 0; i < n; i++)
	{
		if (dataAsc.begin() != dataAsc.end())
		{
			input = *dataAsc.begin();
			maxAnswer += input;
			dataAsc.erase(dataAsc.begin());
			if (input != 1)
				dataAsc.insert(input - 1);
		}
		if (dataDsc.begin() != dataDsc.end())
		{
			input = *dataDsc.begin();
			minAnswer += input;
			dataDsc.erase(dataDsc.begin());
			if (input != 1)
				dataDsc.insert(input - 1);
		}
	}
	cout << minAnswer << ' ' << maxAnswer;
	return 0;
}