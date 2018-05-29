#include <iostream>
#include <algorithm>
using namespace std;

double answer = 0;
int input = 0, n;

int main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		answer += input;
	}
	printf("%.12f", answer / (double)n);
	return 0;
}