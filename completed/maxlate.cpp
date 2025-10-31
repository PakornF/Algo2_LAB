#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    // Each job: deadline D_i and duration C_i
    vector<pair<long long,long long>> jobs(N); // {D, C}
    for (int i = 0; i < N; ++i) {
        long long D, C;
        cin >> D >> C;
        jobs[i] = {D, C};
    }

    // EDD rule (Earliest Due Date) minimizes maximum lateness.
    // Here lateness is (completion - (D + 10)).
    sort(jobs.begin(), jobs.end(),
         [](const pair<long long,long long>& a, const pair<long long,long long>& b){
             if (a.first != b.first) return a.first < b.first; // by D
             return a.second < b.second;                        // tie-break by C
         });

    long long time = 0;        // current completion time
    long long maxOver = 0;     // max overage in days beyond D+10

    for (const auto& job : jobs) {
        long long D = job.first;
        long long C = job.second;
        time += C;
        long long over = time - (D + 10);
        if (over > maxOver) maxOver = over;
    }

    if (maxOver < 0) maxOver = 0;           // no penalty if within 10 days after deadline
    long long answer = maxOver * 1000LL;    // 1,000 baht per day
    
    cout << answer << '\n';
}