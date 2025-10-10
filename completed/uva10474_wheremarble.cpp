#include <iostream>
#include <vector>

using namespace std;

int main() {
    int caseNumber = 1;
    
    while (true) {
        int N, Q;
        cin >> N >> Q;
        
        if (N == 0 && Q == 0) break;
        
        vector<int> marbles(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> marbles[i];
        }
        
        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << caseNumber++ << ":" << endl;
        
        for (int i = 0; i < Q; ++i) {
            int query;
            cin >> query;
            
            bool found = false;
            for (int j = 0; j < N; ++j) {
                if (marbles[j] == query) {
                    cout << query << " found at " << j + 1 << endl;
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                cout << query << " not found" << endl;
            }
        }
    }
}