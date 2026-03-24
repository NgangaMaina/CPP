#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    const int INF = 1000000005;
    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for(int c : coins) {
        if(c > x) continue;
        for(int j = c; j <= x; j++) {
            if(dp[j - c] != INF) {
                dp[j] = min(dp[j], dp[j - c] + 1);
            }
        }
    }

    if(dp[x] == INF) {
    cout << -1 << '\n';
    }else{
        cout << dp[x] << '\n';
    }
    return 0;
}
