#include <iostream>
#include <list>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    if (!(1 <= n && n <= 50000))
        return 1;
    list<int> lst(n, 0);
    auto it = lst.begin();
    for (int i = 0; i < m && i < 200000; i++)
    {
        int t;
        cin >> t;
        if (t == 0)
        {
            it = lst.begin();
        }
        else if (t == 1)
        {
            if (it != lst.end())
                ++it;
        }
        else if (t == 2)
        {
            ++it;
            lst.insert(it--, 0);
        }
        else if (t == 3)
        {
            int x;
            cin >> x;
            if (1 <= x && x <= 1000)
                *it += x;
        }
    }
    for (auto j: lst)
        cout << j << " ";
    cout << endl;
    return 0;
}