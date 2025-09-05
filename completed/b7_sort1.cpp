#include <iostream>

using namespace std;

void myswap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            myswap(&arr[i], &arr[j]);
        }
    }
    myswap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    int arr[100000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = k - 1; i < n; i += k) {
        cout << arr[i] << "\n";
    }
}
