#include <iostream>

using namespace std;

int main() {

    int N, S;

    cin >> N >> S;

    int times[1000];

    for (int i = 0; i < N; ++i) {
        cin >> times[i];
    }

    int speed = 0, max_speed = 0, prev_time = 0;

    for (int i = 0; i < N; ++i) {
        speed = max(0, speed - (times[i] - prev_time));
        speed += S;
        if (speed > max_speed) max_speed = speed;
        prev_time = times[i] + 1;
    }

    cout << max_speed << endl;
}