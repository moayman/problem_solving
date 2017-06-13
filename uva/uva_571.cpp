/* BFS */
#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

string actions[] = { "fill A", "fill B", "pour A B", "pour B A", "empty A", "empty B" };

#define MOVES 6
#define fillA 0
#define fillB 1
#define pourAB 2
#define pourBA 3
#define emptyA 4
#define emptyB 5

struct node
{
	unsigned int A, B, move;
	node(unsigned int _A = 0, unsigned int _B = 0, unsigned int _move = 0)
	{
		A = _A;
		B = _B;
		move = _move;
	}
};

bool visited[1001][1001];
node parent[1001][1001];
deque<node> q;
unsigned int cA, cB, N;

void print(node &n)
{
	if (n.move == MOVES)
		return;

	print(parent[n.A][n.B]);
	cout << actions[n.move] << endl;
}

void processNode(node &parentNode, node &n)
{
	if (!visited[n.A][n.B])
	{
		q.push_back(n);
		visited[n.A][n.B] = true;
		parent[n.A][n.B] = parentNode;
	}
}

void solve()
{
	q = deque<node>();
	node n(0, 0, 6);
	q.push_back(n);
	while (!q.empty())
	{
		node currentNode = q.front();
		q.pop_front();

		if (currentNode.A == N || currentNode.B == N)
		{
			print(currentNode);
			cout << "success" << endl;
			return;
		}

		for (size_t i = 0; i < MOVES; i++)
		{
			switch (i)
			{
			case fillA:
				if (currentNode.A != cA)
					processNode(currentNode, node(cA, currentNode.B, fillA));
				break;
			case fillB:
				if (currentNode.B != cB)
					processNode(currentNode, node(currentNode.A, currentNode.B, fillB));
				break;
			case pourAB:
				if (currentNode.A > 0 && currentNode.B != cB)
				{
					unsigned int availableB = cB - currentNode.B;
					if (availableB >= currentNode.A)
						processNode(currentNode, node(0, currentNode.B + currentNode.A, pourAB));
					else
						processNode(currentNode, node(currentNode.A - availableB, cB, pourAB));
				}
				break;
			case pourBA:
				if (currentNode.B > 0 && currentNode.A != cA)
				{
					unsigned int availableA = cA - currentNode.A;
					if (availableA >= currentNode.B)
						processNode(currentNode, node(currentNode.A + currentNode.B, 0, pourBA));
					else
						processNode(currentNode, node(cA + currentNode.B - availableA, 0, pourBA));
				}
				break;
			case emptyA:
				if (currentNode.A > 0)
					processNode(currentNode, node(0, currentNode.B, emptyA));
				break;
			case emptyB:
				if (currentNode.B > 0)
					processNode(currentNode, node(currentNode.A, 0, emptyA));
				break;
			}
		}
	}
}

int main()
{
#ifdef AYMAN_PC
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while (cin >> cA >> cB >> N)
	{
		memset(visited, false, sizeof visited);
		memset(parent, 0, sizeof parent);
		solve();
	}
	return 0;
}

/* DFS */
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

string toOutput[] = { "fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A" };

#define fillA 0
#define fillB 1
#define emptyA 2
#define emptyB 3
#define pourAB 4
#define pourBA 5

int cA, cB, N;
bool visited[1001][1001];
vector<string> solution;

bool solve(int a, int b)
{
	if (b == N)
	{
		for (size_t i = 0; i < solution.size(); i++)
		{
			cout << solution[i] << endl;
		}
		cout << "success" << endl;
		return true;
	}

	visited[a][b] = true;

	// fill A
	if (!visited[cA][b])
	{
		solution.push_back(toOutput[fillA]);
		if (solve(cA, b))
			return true;
		solution.pop_back();
	}
	// fill B
	if (!visited[a][cB])
	{
		solution.push_back(toOutput[fillB]);
		if (solve(a, cB))
			return true;
		solution.pop_back();
	}
	// empty A
	// fill B
	if (!visited[0][b])
	{
		solution.push_back(toOutput[emptyA]);
		if (solve(0, b))
			return true;
		solution.pop_back();
	}
	// empty B
	if (!visited[a][0])
	{
		solution.push_back(toOutput[emptyB]);
		if (solve(a, 0))
			return true;
		solution.pop_back();
	}
	// pour A B
	if (a >= cB - b)
	{
		if (!visited[a - (cB - b)][cB])
		{
			solution.push_back(toOutput[pourAB]);
			if (solve(a - (cB - b), cB))
				return true;
			solution.pop_back();
		}
	}
	else
	{
		if (!visited[0][a + b])
		{
			solution.push_back(toOutput[pourAB]);
			if (solve(0, a + b))
				return true;
			solution.pop_back();
		}
	}
	// pour B A
	if (b >= cA - a)
	{
		if (!visited[cA][b - (cA - a)])
		{
			solution.push_back(toOutput[pourBA]);
			if (solve(cA, b - (cA - a)))
				return true;
			solution.pop_back();
		}
	}
	else
	{
		if (!visited[a + b][0])
		{
			solution.push_back(toOutput[pourBA]);
			if (solve(a + b, 0))
				return true;
			solution.pop_back();
		}
	}

	return false;
}

int main()
{
#ifdef AYMAN_PC
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while (cin >> cA >> cB >> N)
	{
		solution.clear();
		memset(visited, false, sizeof visited);
		solve(0, 0);
	}
	return 0;
}