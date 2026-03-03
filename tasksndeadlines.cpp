#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    vector<long long> durations(n);
    long long sum_d = 0;
    for(long long i = 0; i < n; i++){
        long long a, d;
        cin >> a >> d;
        durations[i] = a;
        sum_d +=d;
    }
    //Sort the vector in ascending order to apply SPT
    sort(durations.begin(), durations.end());
    long long sum_c = 0;
    for(long long i = 0; i < n; i++) {
        sum_c += durations[i] * (n - i);
    }

    long long max_reward = sum_d - sum_c;
    cout << max_reward << endl;
    return 0;

}
