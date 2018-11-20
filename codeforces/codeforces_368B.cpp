#include <iostream>
#include <set>
using namespace std;

int data[100000], n, m, input;
set<int> answer;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	for (int i = n - 1; i > -1; i--)
	{
		answer.insert(data[i]);
		data[i] = answer.size();
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &input);
		printf("%d\n", data[input - 1]);
	}
	return 0;
}
