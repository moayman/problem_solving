#include <iostream>
#include <functional>
#include <map>
using namespace std;


int main()
{
	long long n, k;
	long long answer = 0;
	char c;
	map<char, long long> data;
	multimap<long long, char, greater<long long>> flipped;
	cin >> n >> k;
	for (size_t i = 0; i < n; i++)
	{
		cin >> c;
		data[c]++;
	}
	for (auto it = data.begin(); it != data.end(); it++)
		flipped.insert(pair<long long, char>(it->second, it->first));
	for (auto it = flipped.begin(); it != flipped.end() && k != 0; it++)
	{
		if (it->first > k)
		{
			answer += k * k;
			k = 0;
		}
		else
		{
			answer += it->first * it->first;
			k -= it->first;
		}
	}
	cout << answer;
	return 0;
}