#include <iostream>
#include <functional>
#include <map>
#include <set>
using namespace std;

int main()
{
	// M must be signed for -ve MOD values to be correct
	int N, M;
	int input;
	while (cin >> N >> M)
	{
		cout << N << " " << M << endl;
		if (N == 0 && M == 0)
			break;
		// first is for odd numbers and second is for even numbers
		map<int, pair<multiset<int, greater<int>>, multiset<int>>> data;
		for (size_t i = 0; i < N; i++)
		{
			cin >> input;
			if (input % 2 != 0)
				data[input % M].first.insert(input);
			else
				data[input % M].second.insert(input);

		}
		for (map<int, pair<multiset<int, greater<int>>, multiset<int>>>::iterator mapIt = data.begin(); mapIt != data.end(); mapIt++)
		{
			multiset<int, greater<int>>::iterator oddEnd = mapIt->second.first.end();
			for (multiset<int, greater<int>>::iterator oddIt = mapIt->second.first.begin(); oddIt != oddEnd; oddIt++)
				cout << *oddIt << endl;
			multiset<int>::iterator evenEnd = mapIt->second.second.end();
			for (multiset<int>::iterator evenIt = mapIt->second.second.begin(); evenIt != evenEnd; evenIt++)
				cout << *evenIt << endl;
		}
	}
	return 0;
}