//#include <iostream>
//#include <cstring>
//#include <sstream>
//#include <string>
//using namespace std;
//
//int weights[30], dp[30][500];
//
//int MAX(const int &a, const int &b)
//{
//	if (a > b)
//		return a;
//	return b;
//}
//
//int knapsack(int n, int w)
//{
//	memset(dp, 0, sizeof dp);
//
//	for (size_t i = 1; i <= n; i++)
//	{
//		for (int limit = 0; limit <= w; limit++)
//		{
//			if (weights[i] <= limit)
//				dp[i][limit] = MAX(dp[i - 1][limit], dp[i - 1][limit - weights[i]] + weights[i]);
//			else
//				dp[i][limit] = dp[i - 1][limit];
//		}
//	}
//	return dp[n][w];
//}
//
//int main()
//{
//	int m, n;
//	cin >> m;
//	cin.ignore();
//	for (size_t a = 0; a < m; a++)
//	{
//		memset(weights, 0, sizeof weights);
//		int sum = 0, n = 0;
//		string s;
//		getline(cin, s);
//		stringstream ss(s);
//		while (ss >> weights[n])
//		{
//			sum += weights[n];
//			++n;
//		}
//		if (sum % 2 == 0 && knapsack(n, sum / 2) * 2 == sum)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;
//}



//#include <iostream>
//#include <cstring>
//#include <sstream>
//#include <string>
//using namespace std;
//
//int sz = 0;
//int v[21];
//
//short dp[20][200];
//
//short solve(int idx, int rem) {
//	if (idx == sz)
//		return rem == 0;
//	short &ret = dp[idx][rem];
//	if (ret != -1)
//		return ret;
//	ret = false;
//	ret |= solve(idx + 1, rem);
//	if (rem >= v[idx])
//		ret |= solve(idx + 1, rem - v[idx]);
//	return ret;
//}
//
//int main() {
//	int tc;
//	cin >> tc;
//	cin.ignore();
//	string str;
//	while (tc--) {
//		getline(cin, str);
//		stringstream ss;
//		ss << str;
//		sz = 0;
//		while (ss >> v[sz++]);
//		sz--;
//		int sum = 0;
//		for (int i = 0; i < sz; i++)
//			sum += v[i];
//		memset(dp, -1, sizeof dp);
//		if (sum & 1)
//			cout << "NO\n";
//		else {
//			if (solve(0, sum / 2))
//				cout << "YES\n";
//			else cout << "NO\n";
//		}
//	}
//	return 0;
//}