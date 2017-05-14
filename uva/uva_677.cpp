#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool foundSolution;
size_t N, walks;
unordered_map<size_t, vector<size_t>> connections;
vector<size_t> currentPath = { 0 };
bool isNodeTaken[10];

void nNodesAway(size_t n)
{
	if (n == walks)
	{
		size_t pathSize = currentPath.size();
		cout << "(1";
		for (size_t i = 1; i < pathSize; i++)
		{
			cout << "," << currentPath[i] + 1;
		}
		cout << ")" << endl;
		foundSolution = true;
		return;
	}
	size_t currentNode = currentPath.back(), edges = connections[currentNode].size();
	for (size_t i = 0; i < edges; i++)
	{
		if (!isNodeTaken[connections[currentNode][i]])
		{
			currentPath.push_back(connections[currentNode][i]);
			isNodeTaken[connections[currentNode][i]] = true;
			nNodesAway(n + 1);
			isNodeTaken[connections[currentNode][i]] = false;
			currentPath.pop_back();
		}
	}
}

int main()
{
	int more = 0;
	do
	{
		if (more != 0)
			cout << endl;
		foundSolution = false;
		cin >> N >> walks;
		connections.clear();
		bool input[10][10] = { 0 };
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cin >> input[i][j];
				if (i && i != j && input[i][j])
					connections[j].push_back(i);
			}
		}
		nNodesAway(0);
		if (!foundSolution)
			cout << "no walk of length " << walks << endl;
	} while (cin >> more);
	return 0;
}