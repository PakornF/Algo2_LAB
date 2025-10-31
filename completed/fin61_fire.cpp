#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    long long R;
    if (!(cin >> N >> R)) return 0;

    vector<long long> x(N);
    for (int i = 0; i < N; ++i) cin >> x[i];
    sort(x.begin(), x.end()); // harmless if already sorted

    int ans = 0;
    int i = 0;
    while (i < N) {
        long long left = x[i];
        long long coverRight = left + 2LL * R;   // place station at left+R

        // skip all garages covered by this station
        while (i < N && x[i] <= coverRight) ++i;

        ++ans;
    }
    cout << ans << '\n';
    }