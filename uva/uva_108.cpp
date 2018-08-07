#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// Solution using modified Kadane algorithm to work on 2D

const int N = 1e2 + 9, M = 1e5 + 9, OO = 0x3f3f3f3f;

int n, A[N][N], maxi;

int main()
{
#ifdef AYMAN_PC
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", A[i] + j);
			A[i][j] += A[i - 1][j];					// Cumulative columns
		}
	}
	for (int top = 1; top <= n; ++top)
	{
		for (int btm = top; btm <= n; ++btm)
		{
			int sum = 0;
			for (int c = 1; c <= n; ++c)		// Kadane Algorithm
			{
				sum += A[btm][c] - A[top - 1][c];
				sum = max(sum, 0);
				maxi = max(maxi, sum);
			}
		}
	}
	printf("%d\n", maxi);
	return 0;
}

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int data[100][100], dp[101][101][101][101], N, maximum;
//
//int main()
//{
//	while (cin >> N)
//	{
//		memset(data, 0, sizeof data);
//		memset(dp, 0, sizeof dp);
//		maximum = 0;
//		for (size_t i = 0; i < N; i++)
//		{
//			for (size_t j = 0; j < N; j++)
//			{
//				cin >> data[i][j];
//				if (i == 0 && j == 0)
//					maximum = data[i][j];
//				if (maximum < data[i][j])
//					maximum = data[i][j];
//				dp[i + 1][j + 1][i + 1][j + 1] = data[i][j];
//			}
//		}
//		N++;
//		for (size_t a = 1; a < N; a++)
//		{
//			for (size_t b = 1; b < N; b++)
//			{
//				for (size_t i = 1; i <= a; i++)
//				{
//					for (size_t j = 1; j <= b; j++)
//					{
//						if (i != a || j != b)
//						{
//							dp[i][j][a][b] = dp[a][j][a][b - 1] + dp[i][b][a - 1][b] + dp[i][j][a - 1][b - 1] + dp[a][b][a][b];
//							if (maximum < dp[i][j][a][b])
//								maximum = dp[i][j][a][b];
//						}
//					}
//				}
//			}
//		}
//		cout << maximum << endl;
//	}
//	return 0;
//}
