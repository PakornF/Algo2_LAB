#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vct;
    int x;
    while (cin >> x)
    {
        vct.push_back(x);
        sort(vct.begin(), vct.end());
        auto middle = vct.size() / 2;
        int median;
        if (vct.size() % 2 == 0)
        {
            median = (vct[middle - 1] + vct[middle]) / 2;
        }
        else
        {
            median = vct[middle];
        }
        cout << median << '\n';
    }
    return 0;
}