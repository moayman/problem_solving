#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main()
{
    int n, t;
    cin >> n >> t;
    string in;
    cin >> in;
    vector<int> pos;
    for (int i = 0, j = 0; i < n; i++)
    {
        if (in[i] == 'B')
            pos.push_back(i);
    }
    while(t) {
        for (int i = 0; i < pos.size(); i++)
        {
            if(pos[i] < n - 1 && in[pos[i] + 1] == 'G') {
                in[pos[i] + 1] = 'B';
                in[pos[i]] = 'G';
                pos[i]++;
            }
        }
        t--;        
    }
    cout << in;
    return 0;
}
