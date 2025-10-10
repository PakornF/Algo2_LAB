#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
    {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        int m; 
        if (!(cin >> m))
            break;

        sort(arr.begin(), arr.end());

        int bestA = -1, bestB = -1;
        int bestDiff = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int need = m - arr[i];
            auto it = lower_bound(arr.begin() + i + 1, arr.end(), need);
            if (it != arr.end() && *it == need) {
                int b = *it;
                int diff = b - arr[i];
                if (diff < bestDiff)
                {
                    bestDiff = diff;
                    bestA = arr[i];
                    bestB = b;
                }
            }
        }
        cout << "Peter should buy books whose prices are " << bestA << " and " << bestB << ".\n\n";
    }
}