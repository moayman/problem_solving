#include <iostream>
using namespace std;

int main()
{
	size_t T, N;
	cin >> T;
	++T;
	for (size_t i = 1; i < T; i++)
	{
		// O(N)
		// Jumps to the same height aren't added
		size_t high_jumps = 0, low_jumps = 0;
		int height, last_height;
		cin >> N >> last_height;
		for (size_t j = 1; j < N; j++)
		{
			cin >> height;
			if (height > last_height)
				++high_jumps;
			else if (height < last_height)
				++low_jumps;
			last_height = height;
		}
		cout << "Case " << i << ": " << high_jumps << " " << low_jumps << endl;
	}
	return 0;
}