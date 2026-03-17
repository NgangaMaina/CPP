#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies(n); //{end, start}
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies[i] = {b, a};

    }

    sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
            });

    //Multiset to find the best fitting time
    multiset<int> availability;
    for(int i = 0; i< k; i++) availability.insert(0);

    int ans = 0;
    for(auto& m : movies) {
        int end_time = m.first;
        int start_time = m.second;

        //Find member with the largest free time what is <= start_time
        auto it = availability.upper_bound(start_time);
        if(it != availability.begin()) {
            --it;
            availability.erase(it);
            availability.insert(end_time);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
