#include <iostream>
using namespace std;

#define diff ('a' - 'A')
char in;

int main()
{
	cin >> in;
	cout << (in >= 'a' ? (char)(in - diff) : in);
	while (cin >> in)
		cout << in;
	return 0;
}