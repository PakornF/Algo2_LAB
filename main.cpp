#include <iostream>

using namespace std;

int swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
    return 0;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    return 0;
}

int main(){
    int n, k;
    cin >> n, k;
    int arr[n];
    for(int i = 0; i <= n; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}