#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// BFS
int visited[30];
map<char, vector<char> > data;

int main()
{
	int t, r, q, cq = 1;
	string c1, c2;
	char currentC, destC;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		cin >> r >> q;
		data.clear();
		if (i)
			cout << endl;
		for (size_t j = 0; j < r; j++)
		{
			cin >> c1 >> c2;
			data[c1[0]].push_back(c2[0]);
			data[c2[0]].push_back(c1[0]);
		}
		for (size_t j = 0; j < q; j++)
		{
			cin >> c1 >> c2;
			currentC = c1[0];
			destC = c2[0];
			vector<pair<char, int> > bq;
			visited[currentC] = cq;
			bq.push_back({ currentC, -1 });
			int index = 0;
			while (currentC != destC)
			{
				for (size_t k = 0; k < data[currentC].size(); k++)
				{
					if (data[currentC][k] != cq)
					{
						bq.push_back({ data[currentC][k], index });
						visited[data[currentC][k] - 'A'] = cq;
					}
				}
				currentC = bq[++index].first;
			}
			string output = "";
			output += bq[index].first;
			while (bq[index].second != -1)
			{
				index = bq[index].second;
				output = bq[index].first + output;
			}
			cout << output << endl;
			cq++;
		}
	}
	return 0;
}