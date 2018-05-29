#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int n, input;
	map<int, vector<int> > data;
	stringstream output;
	cin >> n;
	n *= 2;
	for (size_t i = 1; i <= n; i++)
	{
		cin >> input;
		data[input].push_back(i);
	}
	for (auto it = data.begin(); it != data.end(); it++)
	{
		int size = it->second.size();
		if (size % 2 == 1)
		{
			cout << -1;
			return 0;
		}
		for (size_t i = 0; i < size; i += 2)
			output << it->second[i] << ' ' << it->second[i + 1] << endl;
	}
	cout << output.str();
	return 0;
}