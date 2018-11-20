#include <iostream>
#include <map>
using namespace std;

int n, k, p, t;

int main()
{
	scanf("%d%d", &n, &k);
	map<pair<int, int>, int> data;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &p, &t);
		data[pair<int, int>(p, -t)]++;
	}
	for (auto it = data.rbegin(); it != data.rend(); it++)
	{
		k -= it->second;
		if (k < 1)
		{
			printf("%d", it->second);
			return 0;
		}
	}
	return 0;
}
