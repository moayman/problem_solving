#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<char, int> data;
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for (size_t i = 0; i < s1.size(); i++)
		data[s1[i]]++;
	for (size_t i = 0; i < s2.size(); i++)
		data[s2[i]]++;
	for (size_t i = 0; i < s3.size(); i++)
		data[s3[i]]--;
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if (it->second != 0)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}