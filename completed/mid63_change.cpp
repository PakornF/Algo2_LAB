#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> cases(N);
    
    vector<int> profits(N);
    
    for (int i = 0; i < N; ++i) {
        int Xi, Yi;
        cin >> Xi >> Yi;
        profits[i] = Xi - Yi;
    }

    sort(profits.begin(), profits.end());
    // for (int i = 0; i < N; ++i) {
    //     cout << profits[i] << endl;
    // }

    for (int i = 0; i <= K; i++){
        int sum = 0;
        for (int j = i; j < N; j++){
            sum += profits[j];
        }
        cases[i] = sum;
    }
    for (int i = 0; i <= N; ++i){
        cout << cases[i] << endl;
    }
    auto max_it = max_element(cases.begin(), cases.end());

    // cout << *max_it << endl;
}