#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long Z, D, E;
    if (!(cin >> N >> Z >> D >> E)) return 0;

    vector<long long> X(N);
    for (int i = 0; i < N; ++i) cin >> X[i];
    sort(X.begin(), X.end());

    long long p = 0;      // current car position (at refuel points); start full
    int stops = 0;

    while (true) {
        // If we can drive straight to destination, done.
        if (Z <= p + D) {
            cout << stops << "\n";
            return 0;
        }

        // If we can finish by walking after running out, done (no extra stop).
        if (Z <= p + D + E) {
            cout << stops << "\n";
            return 0;
        }

        // Can we walk to the next station after running out at p + D?
        // Find first station strictly after p + D.
        auto it_after = upper_bound(X.begin(), X.end(), p + D);
        bool can_walk_to_next = (it_after != X.end() && *it_after <= p + D + E);

        if (can_walk_to_next) {
            // Let the car run out, walk to that next station, refill (1 stop), car stays at p + D.
            ++stops;
            p += D;  // car position advances only by driving
            // stations at <= p are now behind us and unusable; loop continues
            continue;
        }

        // Otherwise we must stop before empty: pick the farthest station we can DRIVE to.
        auto it_drive = upper_bound(X.begin(), X.end(), p + D);
        if (it_drive == X.begin()) {
            // No station at or before p + D at all -> impossible
            cout << -1 << "\n";
            return 0;
        }
        --it_drive; // now points to last station with position <= p + D
        if (*it_drive <= p) {
            // All stations <= p: they are behind us -> impossible
            cout << -1 << "\n";
            return 0;
        }

        // Drive to this station and refill (counts a stop). Car position becomes that station.
        ++stops;
        p = *it_drive;
        // Loop repeats with full tank at new p.
    }
}