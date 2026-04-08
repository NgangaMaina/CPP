#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    if(n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<ll> prev(m + 2, 0);
    vector<ll> curr(m + 2, 0);

    for(int j = 1; j <= m; j++) {
        if(x[0] == 0 || x[0] == j) {
            prev[j] = 1;
        }
    }

    for(int i = 1; i < n; i++) {
        fill(curr.begin(), curr.end(), 0);

        for(int j = 1; j <= m; j++) {
            if(x[i] != 0 && x[i]!= j) continue;

            ll ways = 0;
            if(j - 1 >= 1) ways = (ways + prev[j - 1]) % MOD;
            ways = (ways + prev[j]) % MOD;
            if(j + 1 <= m) ways = (ways + prev[j + 1]) % MOD;

            curr[j] = ways;
        }

        prev.swap(curr);
    }

    ll answer = 0;
    for(int j = 1; j <= m; j++){
        answer = (answer  + prev[j]) % MOD;
    }

    cout << answer << "\n";
    return 0;
}
