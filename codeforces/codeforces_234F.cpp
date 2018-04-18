#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f
#define COLOR1 true
#define COLOR2 false

int n, a, b, data[300], dp[300][50000][2]; // prevcolor is required for memoization

int solve(int i = 0, int c1 = a, int c2 = b, bool prevcolor = COLOR1)
{
	if (i == n)
		return 0;
	if (dp[i][c1][prevcolor] != -1)
		return dp[i][c1][prevcolor];
	int c1unattractiveness = i == 0 ? 0 : prevcolor == COLOR1 ? 0 : min(data[i - 1], data[i]);
	int c2unattractiveness = i == 0 ? 0 : prevcolor == COLOR2 ? 0 : min(data[i - 1], data[i]);
	return dp[i][c1][prevcolor] = min(((c2 >= data[i]) ? (solve(i + 1, c1, c2 - data[i], COLOR2) + c2unattractiveness) : INF), ((c1 >= data[i]) ? (solve(i + 1, c1 - data[i], c2, COLOR1) + c1unattractiveness) : INF));
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	memset(dp, -1, sizeof dp); // had to use -1 as initial value
	cin >> n >> a >> b;
	for (size_t i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	int solution = solve();
	cout << (solution == INF ? -1 : solution);
	return 0;
}
