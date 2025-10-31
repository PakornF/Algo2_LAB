#include <iostream>
#include <vector>

using namespace std;
//flower
int main() {
    int n;
    cin >> n;
    vector<int> flowers(n);

    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }

    int ans = 1;

    for (int l = 0; l < n; l++){
        for (int r = l; r < n; r++){
            if (flowers[l] != flowers[r]){
                continue;
            }
            int diffFlower = -1;
            int diffCount = 0;
            bool valid = true;
            int i = l;
            while (i <= r){
                int j = i;
                //skip 
                while(j <= r && flowers[j] == flowers[i]){
                    j++;
                }
                if (flowers[i] != flowers[l]){
                    diffCount++;
                    if (diffCount > 1){
                        valid = false;
                        break;
                    }
                    diffFlower = flowers[i];
                }
                i = j;
            }
            if (valid){
                ans = max(ans, r - l + 1);
            }
        }
    }
    cout << ans << "\n";
}