#include <iostream>
using namespace std;

int t, n;

int main()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        if (n == 1)
            cout << -1 << endl;
        else
        {
            cout << 2;
            for (int j = 1; j < n; ++j)
            {
                cout << 3;
            }
            cout << endl;
        }
    }
    return 0;
}
