#include <iostream>
using namespace std;

int main()
{
	size_t N;
	unsigned int A, B, C, a, b, c;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> A >> B >> C;
		for (long long x = -100; x < 100; x++)
		{
			for (long long y = -100; y < 100; y++)
			{
				for (long long z = -100; z < 100; z++)
				{
					c = x*x + y*y + z*z;
					if (c == C)
					{
						b = x*y*z;
						if (b == B)
						{
							a = x + y + z;
							if (a == A)
							{
								if (x != y && x != z && y != z)
								{
									cout << x << " " << y << " " << z << endl;
									goto BREAK;
								}
							}
						}
					}
				}
			}
		}
		cout << "No solution." << endl;
	BREAK:
		;
	}
	return 0;
}