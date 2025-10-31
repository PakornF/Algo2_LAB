#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, L;
    cin >> M >> N >> L;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    vector<int> S; // stack of item TYPES

    for (int step = 0; step < L; step++) {
        int T;
        cin >> T;

        if (T == 1) {
            // push i
            int i;
            cin >> i;
            // item i has type P[i-1]
            S.push_back(P[i - 1]);

        } else if (T == 2) {
            // swap last two
            int sz = (int)S.size();
            int t1 = S[sz - 1];
            int t2 = S[sz - 2];
            S[sz - 1] = t2;
            S[sz - 2] = t1;

        } else if (T == 3) {
            // combine_top a b c
            long long a, b, c;
            cin >> a >> b >> c;

            // take last two: x = last, y = second last
            int x = S.back();
            S.pop_back();
            int y = S.back();
            S.pop_back();

            long long newType = (a * x + b * y + c) % M;
            S.push_back((int)newType);

        } else if (T == 4) {
            // combine_with i a b c
            int i;
            long long a, b, c;
            cin >> i >> a >> b >> c;

            int y = S.back(); // last item type
            S.pop_back();

            int x = P[i - 1]; // item i type

            long long newType = (a * x + b * y + c) % M;
            S.push_back((int)newType);
        }
    }

    // result is last item in S
    cout << S.back() << "\n";

    return 0;
}