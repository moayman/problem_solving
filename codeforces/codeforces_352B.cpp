#include <iostream>
#include <set>
#include <vector>
#include <sstream>
using namespace std;

int n, in, count;
set<int> input;
vector<vector<int> > data(100001);
stringstream output;

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> in;
        input.insert(in);
        data[in].push_back(i);
    }
    for(auto it = input.begin(); it != input.end(); ++it)
    {
        if(data[*it].size() > 1)
        {
            int diff = data[*it][1] - data[*it][0];
            bool failed = false;
            for(int i = 2; i < data[*it].size(); ++i)
            {
                if(data[*it][i] - data[*it][i - 1] != diff)
                {
                    failed = true;
                    break;
                }
            }
            if(!failed)
            {
                ++count;
                output << *it << " " << diff << "\n";
            }
        }
        else
        {
            ++count;
            output << *it << " 0\n";
        }
    }
    cout << count << "\n" << output.str();
    return 0;
}
