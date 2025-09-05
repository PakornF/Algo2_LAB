#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int hours[32];
    for (int i = 1; i <= 31; i++) {
        hours[i] = 0;
    }

    int work_count = 0;

    for (int i = 0; i < N; i++) {
        int A, B, H;
        cin >> A >> B >> H;

        bool take_work = true;

        for (int d = A; d <= B; d++) {
            if (hours[d] + H > 6) {
                take_work = false;
                break;
            }
        }

        if (take_work) {
            for (int d = A; d <= B; d++) {
                hours[d] += H;
            }
            work_count++;
        }
    }

    cout << work_count << "\n";
}
