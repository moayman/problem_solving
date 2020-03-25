#include <iostream>
using namespace std;

int t, a, b, x, y;
int area[4];

#define max(n1, n2) (n1 > n2 ? n1 : n2)

int main()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> a >> b >> x >> y;
        area[0] = y > 0 ? a * y : -1; // UP
		area[1] = x > 0 ? x * b : -1; // LEFT
		area[2] = a * (b - y - 1); // DOWN
		area[3] = (a - x - 1) * b; // RIGHT
        cout << max(max(area[0], area[1]), max(area[2], area[3])) << endl;
    }
    return 0;
}
