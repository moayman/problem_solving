#include <iostream>
#include <algorithm>
using namespace std;

int t, a, b, c, input[3], answer;

int main()
{
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		answer = 0;
		cin >> input[0] >> input[1] >> input[2];
		sort(input, input + 3);
		a = input[0];
		b = input[1];
		c = input[2];
		if (c > 0){
			c--; answer++;
		}
		if (b > 0){
			b--; answer++;
		}
		if (a > 0){
			a--; answer++;
		}
		if (c > 0 && b > 0){
			c--; b--; answer++;
		}
		if (c > 0 && a > 0){
			c--; a--; answer++;
		}
		if (a > 0 && b > 0){
			a--; b--; answer++;
		}
		if (a > 0 && b > 0 && c > 0){
			a--; b--; c--; answer++;
		}
		cout << answer << endl;
	}
	return 0;
}
