#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MOVES 6

#define fillA 0
#define fillB 1
#define emptyA 2
#define emptyB 3
#define pourAB 4
#define pourBA 5

bool solved;
unsigned int cA, cB, N, currentNode;

struct node{
	unsigned int action, currentA, currentB, availableA, availableB;
	node* parent;
	node(unsigned int a, unsigned int ca, unsigned int cb, node* p)
	{
		currentA = ca;
		currentB = cb;
		availableA = cA - ca;
		availableB = cB - cb;
		action = a;
		parent = p;
	}
	node()
	{
		currentA = 0;
		currentB = 0;
		availableA = 0;
		availableB = 0;
		action = MOVES;
		parent = NULL;
	}
	bool isSolved()
	{
		return currentB == N;
	}
};

vector<node*> toExpand;

void expand(node * n)
{
	for (size_t i = 0; i < MOVES && !solved; i++)
	{
		switch (i)
		{
		case fillA:
			if (n->currentA != cA)
			{
				toExpand.push_back(new node(fillA, cA, n->currentB, n));
				if (toExpand.back()->isSolved())
					solved = true;
			}
			break;
		case fillB:
			if (n->currentB != cB)
			{
				toExpand.push_back(new node(fillB, n->currentA, cB, n));
				if (toExpand.back()->isSolved())
					solved = true;
			}
			break;
		case emptyA:
			if (n->currentA > 0)
			{
				toExpand.push_back(new node(emptyA, 0, n->currentB, n));
				if (toExpand.back()->isSolved())
					solved = true;
			}
			break;
		case emptyB:
			if (n->currentB > 0)
			{
				toExpand.push_back(new node(emptyB, n->currentA, 0, n));
				if (toExpand.back()->isSolved())
					solved = true;
			}
			break;
		case pourAB:
			if (n->currentA > 0 && n->currentB != cB)
			{
				if (n->availableB > n->currentA)
				{
					toExpand.push_back(new node(pourAB, 0, n->currentB + n->currentA, n));
					if (toExpand.back()->isSolved())
						solved = true;
				}
				else
				{
					toExpand.push_back(new node(pourAB, n->currentA - n->availableB, n->currentB + n->availableB, n));
					if (toExpand.back()->isSolved())
						solved = true;
				}
			}
			break;
		case pourBA:
			if (n->currentB > 0 && n->currentA != cA)
			{
				if (n->availableA > n->currentB)
				{
					toExpand.push_back(new node(pourBA, n->currentA + n->currentB, 0, n));
					if (toExpand.back()->isSolved())
						solved = true;
				}
				else
				{
					toExpand.push_back(new node(pourBA, n->currentA + n->availableA, n->currentB - n->availableA, n));
					if (toExpand.back()->isSolved())
						solved = true;
				}
			}
			break;
		}
	}
	currentNode++;
}

int main()
{
	bool endline = false;
	while (scanf("%u %u %u", &cA, &cB, &N) == 3)
	{
		if (endline)
			printf("\n");
		toExpand.clear();
		solved = false;
		currentNode = 0;
		node* root = new node();
		toExpand.push_back(root);
		while (!solved && currentNode < toExpand.size())
		{
			expand(toExpand[currentNode]);
		}
		root = toExpand.back();
		string toPrint;
		do
		{
			switch (root->action)
			{
			case fillA:
				toPrint = ("fill A\n") + toPrint;
				break;
			case fillB:
				toPrint = ("fill B\n") + toPrint;
				break;
			case emptyA:
				toPrint = ("empty A\n") + toPrint;
				break;
			case emptyB:
				toPrint = ("empty B\n") + toPrint;
				break;
			case pourAB:
				toPrint = ("pour A B\n") + toPrint;
				break;
			case pourBA:
				toPrint = ("pour B A\n") + toPrint;
				break;
			}
			root = root->parent;
		} while (root != NULL);
		printf("%ssuccess", toPrint.c_str());
		endline = true;
	}
	return 0;
}