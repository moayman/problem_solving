#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	size_t T, N, M;
	int input;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		unordered_map<int, unsigned int> list1, list2;
		unsigned int output = 0;
		cin >> N >> M;
		for (size_t j = 0; j < N; j++)
		{
			cin >> input;
			list1[input]++;
		}
		for (size_t j = 0; j < M; j++)
		{
			cin >> input;
			if (list1.find(input) != list1.end())
			{
				list1[input]--;
				if (list1[input] == 0)
					list1.erase(input);
			}
			else
			{
				list2[input]++;
				output++;
			}
		}
		for (unordered_map<int, unsigned int>::iterator it = list1.begin(); it != list1.end(); it++)
		{
			output += it->second;
		}
		cout << output << endl;
	}
	return 0;
}