#include <iostream>
#include <set>
using namespace std;

int main()
{
	char c;
	set<char> data;
	while (cin >> c)
		data.insert(c);
	cout << (data.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");
	return 0;
}