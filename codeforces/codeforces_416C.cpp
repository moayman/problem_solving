#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// Gotta improve this shit

int n, k;
vector<pair<int, int>> tables(1000);
vector<bool> tableTaken(1000);
vector<pair<int, pair<int, int>>> requests(1000);
int input1, input2;
stringstream output;
int numberOfTakenTables = 0, money = 0;

int main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input1 >> input2;
		requests[i] = pair<int, pair<int, int>>(input2, pair<int, int>(input1, i + 1));
	}
	sort(requests.begin(), requests.begin() + n, greater<pair<int, pair<int, int>>>());
	cin >> k;
	for (size_t i = 0; i < k; i++)
	{
		cin >> input1;
		tables[i] = pair<int, int>(input1, i + 1);
	}
	sort(tables.begin(), tables.begin() + k);
	for (size_t i = 0; i < n; i++)
	{
		int &toSeat = requests[i].second.first;
		for (size_t j = 0; j < k; j++)
		{
			if (!tableTaken[j])
			{
				if (tables[j].first >= toSeat)
				{
					tableTaken[j] = true;
					money += requests[i].first;
					numberOfTakenTables++;
					output << requests[i].second.second << " " << tables[j].second << "\n";
					break;
				}
			}
		}
	}
	cout << numberOfTakenTables << " " << money << "\n";
	cout << output.str();
	return 0;
}
