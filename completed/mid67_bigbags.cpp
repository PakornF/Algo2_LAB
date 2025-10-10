#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int count = 0;
    long long int sum = 0;

    vector<long long int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++) {
        int j = 0;
        for (; j < k && j < i; j++) {
            sum += arr[j];
        }
        if (sum <= arr[i] && j == k) {
            count++;
        }
        sum = 0;
    }
    cout << count << endl;
}