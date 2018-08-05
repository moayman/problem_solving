#include <iostream>
using namespace std;

void updateR(long long& r0, long long& r1, const long long& r){
	long long t = r0 - r*r1;
	r0 = r1;
	r1 = t;
}


//Extended Euclidean Algorithm
long long eGCD(long long r0, long long r1, long long& x0, long long& y0){
	long long y1 = x0 = 1, x1 = y0 = 0;
	while (r1){
		long long r = r0 / r1;
		updateR(r0, r1, r);
		updateR(x0, x1, r);
		updateR(y0, y1, r);
	}
	return r0;
}


//Linear Diophantine Equation
bool solve_LDE(long long a, long long b, long long c, long long& x, long long& y, long long& g){
	g = eGCD(a, b, x, y);
	long long m = c / g;
	x *= m;
	y *= m;
	return !(c%g);
}

int main()
{
	long long a, b, x, y, g, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	c = -c;
	if (solve_LDE(a, b, c, x, y, g))
		printf("%lld %lld\n", x, y);
	else
		printf("-1");
	return 0;
}