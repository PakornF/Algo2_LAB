#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int plateau = 0,swamp = 0;
    if (n < 2) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // plateau
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i]) {
            int tmp = 1;
            while (arr[i] == arr[i+1]) {
                i++;
                tmp++;
            }
            if (arr[i] > arr[i + 1] && i + 1 < n) {
                plateau += tmp;
            };
        }
    }
    // swamp
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            int tmp = 1;
            while (arr[i] == arr[i+1]) {
                i++;
                tmp++;
            }
            if (arr[i] < arr[i + 1] && i + 1 < n) {
                swamp += tmp;
            };
        }
    }
    cout << plateau << " " << swamp << endl;
}