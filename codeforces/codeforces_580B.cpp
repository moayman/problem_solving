#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

// two pointers method

pair<long long, long long> data[100000];
long long n, d;
long long maxFriendship = -1, friendship = 0;

int main()
{
	long long in1, in2;
	cin >> n >> d;
	for (size_t i = 0; i < n; i++)
	{
		cin >> in1 >> in2;
		data[i] = pair<long long, long long>(in1, in2);
	}
	sort(data, data + n, greater<pair<long long, long long>>());
	for (long long i = 0, j = 0; i < n; friendship -= data[i].second, i++)
	{
		while (j < n && abs(data[i].first - data[j].first < d))
		{
			friendship += data[j++].second;
		}
		if (friendship > maxFriendship)
			maxFriendship = friendship;
	}
	cout << maxFriendship;
	return 0;
}