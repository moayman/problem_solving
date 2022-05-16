#include <iostream>
#include <unordered_set>
using namespace std;

bool isDistinct(int data)
{
    int a = data % 10;
    data /= 10;
    int b = data % 10;
    data /= 10;
    int c = data % 10;
    data /= 10;
    int d = data % 10;
    if (!(a == b || a == c || a == d ||
          b == c || b == d ||
          c == d))
        return true;
    return false;
    // unordered_set<int> distinct;
    // while (data) {
    //     distinct.insert(data % 10);
    //     data /= 10;
    // }
    // return distinct.size() == 4;
}

int main()
{
    int data;
    cin >> data;
    while (!isDistinct(++data))
    {
    }
    cout << data;
    return 0;
}