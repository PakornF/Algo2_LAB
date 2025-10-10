#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<long long> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];

    long long profit = 0;
    bool holding = false;
    long long buyPrice = 0;

    for (int i = 1; i < N; ++i) {
        long long diff = P[i] - P[i - 1];

        if (!holding && diff >= K) {
            holding = true;
            buyPrice = P[i];
        } else if (holding && diff <= -K) {
            holding = false;
            profit += (P[i] - buyPrice);
        }
    }
    cout << profit << "\n";
}