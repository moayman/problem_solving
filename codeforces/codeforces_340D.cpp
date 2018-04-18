#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, data[100001];

int binarySearchLIS(){
	vector<int> ret;
	for (int i = 0; i < n; i++){
		auto it = lower_bound(ret.begin(), ret.end(), data[i]);
		if (it == ret.end()) ret.push_back(data[i]);
		else *it = data[i];
	}
	return (int)ret.size();
}

int main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
		cin >> data[i];
	cout << binarySearchLIS();
	return 0;
}
