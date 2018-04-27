#include <iostream>
#include <string>
#include <cstring>
using namespace std;

double vp, vd, t, f, c;

int main()
{
	cin >> vp >> vd >> t >> f >> c;
	if (vp >= vd)
	{
		cout << "0";
		return 0;
	}
	int numberOfBojous = 0;
	double timeToHaveTheDragonBack = 0, overtakePosition = 0;
	double princessPosition = vp * t;
	while (princessPosition < c)
	{
		overtakePosition = vd * princessPosition / (vd - vp);
		if (overtakePosition < c)
			numberOfBojous++;
		timeToHaveTheDragonBack = (overtakePosition / vd) + f;
		princessPosition = (vp * timeToHaveTheDragonBack) + overtakePosition;
	}
	cout << numberOfBojous;
	return 0;
}
