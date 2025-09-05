#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    map<int, int> freq;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    vector<pair<int, int>> v;
    v.reserve(freq.size());
    for (auto &p : freq)
    {
        v.push_back({p.first, p.second});
    }

    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first; });

    for (auto &p : v)
    {
        cout << p.first << "\n";
    }
}