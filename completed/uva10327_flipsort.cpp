#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    while (cin >> n){

        int count = 0;
        vector<int> num;

        for (int i = 0 ; i < n ; i++){
            int val;
            cin >> val;
            num.push_back(val);
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (num[j] > num[j + 1]) {
                    swap(num[j], num[j + 1]);
                    count++;
                }
            }
        }

        cout << "Minimum exchange operations : " << count << endl;

    }

}