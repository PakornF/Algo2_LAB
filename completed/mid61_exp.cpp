#include <iostream>

using namespace std;

int DvdbyFour(int num) {
    return (num+1) % 4 == 0;
}

int sum(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += arr[i];
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        if (DvdbyFour(i)) {
            arr[i] *= 2;
        }
    }
    cout << sum(arr, n) << endl;
}