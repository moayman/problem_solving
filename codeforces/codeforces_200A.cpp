#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct pairHash {
	size_t operator()(const std::pair<long long, long long>& p) const {
		return p.first ^ p.second;
	}
};

struct pointInfo
{
	long long next;
	vector<pair<long long, long long>> toSearch;
	unordered_map<pair<long long, long long>, bool, pairHash> visited;
	pointInfo(long long i, long long j)
	{
		next = 0;
		toSearch.push_back(pair<long long, long long>(i, j));
		visited[pair<long long, long long>(i, j)] = true;
	}
	pointInfo()
	{
		next = -1;
	}
};

void main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	long long n, m, i, j;
	unordered_map<pair<long long, long long>, pointInfo, pairHash> info;
	size_t k;
	cin >> n >> m >> k;
	vector<vector<bool>> data(n, vector<bool>(m, false));
	for (size_t l = 0; l < k; l++)
	{
		cin >> i >> j;
		i--; j--;
		if (data[i][j] == false)
		{
			data[i][j] = true;
			cout << i + 1 << " " << j + 1 << endl;
		}
		else
		{
			unordered_map<pair<long long, long long>, pointInfo, pairHash>::iterator currentPointInfo = info.find(pair<long long, long long>(i, j));
			size_t it = 0;
			if (currentPointInfo != info.end())
			{
				it = currentPointInfo->second.next;
			}
			else
			{
				info[pair<long long, long long>(i, j)] = pointInfo(i, j);
				currentPointInfo = info.find(pair<long long, long long>(i, j));
			}
			vector<pair<long long, long long>>* toSearch = &currentPointInfo->second.toSearch;
			unordered_map<pair<long long, long long>, bool, pairHash>* visited = &currentPointInfo->second.visited;
			bool done = false;
			for (; !done && it < toSearch->size(); it++)
			{
				pair<long long, long long> currentPoint = toSearch->at(it), adj = toSearch->at(it);

				adj.first--;
				if (adj.first > -1 && adj.second > -1 && adj.first < n && adj.second < m)
				{
					if (!done && data[adj.first][adj.second] == false)
					{
						data[adj.first][adj.second] = true;
						(*visited)[pair<long long, long long>(adj.first, adj.second)] = true;
						toSearch->push_back(adj);
						cout << adj.first + 1 << " " << adj.second + 1 << endl;
						currentPointInfo->second.next++;
						done = true;
					}
					if ((*visited)[pair<long long, long long>(adj.first, adj.second)] == false)
						toSearch->push_back(adj);
				}

				adj.first++;
				adj.second--;
				if (adj.first > -1 && adj.second > -1 && adj.first < n && adj.second < m)
				{
					if (!done && data[adj.first][adj.second] == false)
					{
						data[adj.first][adj.second] = true;
						(*visited)[pair<long long, long long>(adj.first, adj.second)] = true;
						toSearch->push_back(adj);
						cout << adj.first + 1 << " " << adj.second + 1 << endl;
						currentPointInfo->second.next++;
						done = true;
					}
					if ((*visited)[pair<long long, long long>(adj.first, adj.second)] == false)
						toSearch->push_back(adj);
				}

				adj.second += 2;
				if (adj.first > -1 && adj.second > -1 && adj.first < n && adj.second < m)
				{
					if (!done && data[adj.first][adj.second] == false)
					{
						data[adj.first][adj.second] = true;
						(*visited)[pair<long long, long long>(adj.first, adj.second)] = true;
						toSearch->push_back(adj);
						cout << adj.first + 1 << " " << adj.second + 1 << endl;
						currentPointInfo->second.next++;
						done = true;
					}
					if ((*visited)[pair<long long, long long>(adj.first, adj.second)] == false)
						toSearch->push_back(adj);
				}

				adj.first++;
				adj.second--;
				if (adj.first > -1 && adj.second > -1 && adj.first < n && adj.second < m)
				{
					if (!done && data[adj.first][adj.second] == false)
					{
						data[adj.first][adj.second] = true;
						(*visited)[pair<long long, long long>(adj.first, adj.second)] = true;
						toSearch->push_back(adj);
						cout << adj.first + 1 << " " << adj.second + 1 << endl;
						currentPointInfo->second.next++;
						done = true;
					}
					if ((*visited)[pair<long long, long long>(adj.first, adj.second)] == false)
						toSearch->push_back(adj);
				}

				adj.first -= 2;
				adj.second--;
				if (adj.first > -1 && adj.second > -1 && adj.first < n && adj.second < m)
				{
					if (!done && data[adj.first][adj.second] == false)
					{
						data[adj.first][adj.second] = true;
						(*visited)[pair<long long, long long>(adj.first, adj.second)] = true;
						toSearch->push_back(adj);
						cout << adj.first + 1 << " " << adj.second + 1 << endl;
						currentPointInfo->second.next++;
						done = true;
					}
					if ((*visited)[pair<long long, long long>(adj.first, adj.second)] == false)
						toSearch->push_back(adj);
				}

				adj.second += 2;
				if (adj.first > -1 && adj.second > -1 && adj.first < n && adj.second < m)
				{
					if (!done && data[adj.first][adj.second] == false)
					{
						data[adj.first][adj.second] = true;
						(*visited)[pair<long long, long long>(adj.first, adj.second)] = true;
						toSearch->push_back(adj);
						cout << adj.first + 1 << " " << adj.second + 1 << endl;
						currentPointInfo->second.next++;
						done = true;
					}
					if ((*visited)[pair<long long, long long>(adj.first, adj.second)] == false)
						toSearch->push_back(adj);
				}

				adj.first += 2;
				adj.second -= 2;
				if (adj.first > -1 && adj.second > -1 && adj.first < n && adj.second < m)
				{
					if (!done && data[adj.first][adj.second] == false)
					{
						data[adj.first][adj.second] = true;
						(*visited)[pair<long long, long long>(adj.first, adj.second)] = true;
						toSearch->push_back(adj);
						cout << adj.first + 1 << " " << adj.second + 1 << endl;
						currentPointInfo->second.next++;
						done = true;
					}
					if ((*visited)[pair<long long, long long>(adj.first, adj.second)] == false)
						toSearch->push_back(adj);
				}

				adj.second += 2;
				if (adj.first > -1 && adj.second > -1 && adj.first < n && adj.second < m)
				{
					if (!done && data[adj.first][adj.second] == false)
					{
						data[adj.first][adj.second] = true;
						(*visited)[pair<long long, long long>(adj.first, adj.second)] = true;
						toSearch->push_back(adj);
						cout << adj.first + 1 << " " << adj.second + 1 << endl;
						currentPointInfo->second.next++;
						done = true;
					}
					if ((*visited)[pair<long long, long long>(adj.first, adj.second)] == false)
						toSearch->push_back(adj);
				}
			}
		}
	}
}