#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x;
    cin >> n >> x;

    vector<long long> coins(n);
    for(auto& c : coins){
        cin >> c;
    }

    const long long MOD = 1000000007LL;

    vector<long long> dp(x + 1, 0LL);
    dp[0] = 1;

    for(long long c : coins) {
        for(long long j = c; j <= x; ++j){
            dp[j] = (dp[j] + dp[j - c]) % MOD;
        }
    }

    cout << dp[x] << endl;
    return 0;
}
