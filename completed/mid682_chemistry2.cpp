#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, l;
    cin >> n >> l;
    vector<int> items(n);

    for (int i = 0; i < n; i++){
        cin >> items[i];
    }
    
    for (int j = 0; j < l; j++){
        int a, b, c;
        cin >> a >> b >> c;

        vector<int> newItems;

        for (auto x : items){
            newItems.push_back(x);

            // Chk top 2 itemss
            int sz = newItems.size();
            if (sz >= 2 && newItems[sz-2] == a && newItems[sz-1] == b){
                newItems.pop_back();
                newItems.pop_back();
                newItems.push_back(c);
            }
        }
        items.swap(newItems);
    }
    cout << items.size() << "\n";
}