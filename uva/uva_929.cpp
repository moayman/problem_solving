#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// Had to use (N+E)logN Dijkstra
// N^2 Dijkstra TLEs

#define N 10000000
#define INF 0x3f3f3f3f

int dis[N];
int n, m;
int head[N], nxt[N], to[N], cst[N];
int ne;

void init(){
	memset(head, -1, sizeof head);
	ne = 0;
}

void addEdge(int f, int t, int c){
	nxt[ne] = head[f];
	to[ne] = t;
	cst[ne] = c;
	head[f] = ne++;
}

void Dijkstra()
{
	memset(dis, INF, sizeof dis);
	priority_queue<pair<int, int> > q;
	q.push({ -cst[0], 0 });
	dis[0] = cst[0];
	while (q.size()){
		int d = -q.top().first, u = q.top().second;
		q.pop();
		if (dis[u] != d)	continue;
		for (int k = head[u]; ~k; k = nxt[k]){
			int v = to[k], c = cst[v];
			int dd = d + c;
			if (dis[v] > dd){
				dis[v] = dd;
				q.push({ -dd, v });
			}
		}
	}
}

int getIndex(int r, int c)
{
	return r * m + c;
}

bool isValid(int r, int c)
{
	return c > -1 && r > -1 && r < n && c < m;
}

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int main()
{
	int t;
	scanf("%d", &t);
	for (size_t i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		init();
		for (size_t r = 0; r < n; r++)
		{
			for (size_t c = 0; c < m; c++)
			{
				int index = getIndex(r, c);
				scanf("%d", &cst[index]);
				for (size_t neigh = 0; neigh < 4; neigh++)
				{
					if (isValid(r + dr[neigh], c + dc[neigh]))
						addEdge(index, getIndex(r + dr[neigh], c + dc[neigh]), cst[index]);
				}
			}
		}
		Dijkstra();
		printf("%d\n", dis[n * m - 1]);
	}
	return 0;
}
