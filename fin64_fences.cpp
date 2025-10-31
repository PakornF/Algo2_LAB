#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long L;
    if (!(cin >> N >> L)) return 0;

    vector<pair<long long,long long>> a(N); // {Si, Ti}
    for (int i = 0; i < N; ++i) cin >> a[i].first >> a[i].second;

    // Problem states houses are ordered and non-overlapping; sorting is harmless for robustness.
    sort(a.begin(), a.end());

    long long current_right = LLONG_MIN; // right end of the current fence coverage
    int fences = 0;

    for (int i = 0; i < N; ++i) {
        long long Si = a[i].first;
        long long Ti = a[i].second;

        // If current house not fully covered by the current fence, start a new one at Si.
        if (Ti > current_right) {
            ++fences;
            current_right = Si + L; // fence at X=Si covers [Si, Si+L]
        }
        // else: already covered; continue
    }
    cout << fences << '\n';
}