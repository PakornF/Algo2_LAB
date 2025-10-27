#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n), quality(n);
    for (int i = 0; i < n; i++) cin >> arr[i] >> quality[i];

    vector<int> token(m), request(m);
    for (int i = 0; i < m; i++) cin >> token[i] >> request[i];

    int sum = 0;
    int discard = 0;

    for (int i = 0; i < m; i++) {
        int needT = token[i], needR = request[i];
        int bestIdx = -1, bestQ = 300000000;
        for (int j = 0; j < n; j++) {
            if (quality[j] >= needR && arr[j] >= needT) {
                if (quality[j] < bestQ) {
                    bestQ = quality[j];
                    bestIdx = j;
                }
            }
        }
        if (bestIdx == -1) {
            discard++;
        } else {
            arr[bestIdx] -= needT;
            sum += 1 * needT * quality[bestIdx];
        }
    }
    cout << sum << " " << discard << "\n";
}
