#include <iostream>
#include <map>
using namespace std;

int main()
{
	size_t N;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		unsigned long long max, sumOfMin3Sides;
		unsigned long long sides[4] = { 0 };
		map<unsigned long long, int> lengths;
		cin >> sides[0] >> sides[1] >> sides[2] >> sides[3];
		lengths[sides[0]]++;
		lengths[sides[1]]++;
		lengths[sides[2]]++;
		lengths[sides[3]]++;
		size_t size = lengths.size();
		if (size == 1)
		{
			cout << "square" << endl;
		}
		else if (size == 2 && (*lengths.crbegin()).second == 2)
		{
			cout << "rectangle" << endl;
		}
		else
		{
			sumOfMin3Sides = sides[0] + sides[1] + sides[2] + sides[3];
			max = (*(lengths.crbegin())).first;
			sumOfMin3Sides -= max;
			if (sumOfMin3Sides <= max)
			{
				cout << "banana" << endl;
			}
			else
			{
				cout << "quadrangle" << endl;
			}
		}
	}
	return 0;
}