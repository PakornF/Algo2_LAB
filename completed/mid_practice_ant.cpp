#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int total = 0;
    bool mustSkip = false;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (mustSkip) {
            mustSkip = false;   // anteater skips today
        } else {
            int eaten = (a > 1000 ? 1000 : a);
            total += eaten;
            mustSkip = (eaten == 1000);  // if ate 1000, skip tomorrow
        }
    }

    cout << total << endl;
}