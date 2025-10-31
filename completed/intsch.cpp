#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<pair<long long,long long>> intervals(N);
    for (int i = 0; i < N; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    // Sort by finishing time (then by start time)
    sort(intervals.begin(), intervals.end(), [](const pair<long long,long long> &a, const pair<long long,long long> &b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    long long last_end = numeric_limits<long long>::min();
    int count = 0;

    for (size_t i = 0; i < intervals.size(); ++i) {
        long long s = intervals[i].first;
        long long t = intervals[i].second;

        if (s >= last_end) {
            ++count;
            last_end = t;
        }
    }
    cout << count << '\n';
}