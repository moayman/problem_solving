#include <iostream>
#include <map>
using namespace std;

int main()
{
	char input;
	int numberOfOdds = 0;
	map<char, int> data;
	while (cin >> input)
		data[input]++;
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if (it->second % 2 == 1)
		{
			numberOfOdds++;
		}
	}
	if (numberOfOdds > 1)
		cout << ((numberOfOdds - 1) % 2 == 0 ? "First" : "Second");
	else
		cout << "First";
	return 0;
}