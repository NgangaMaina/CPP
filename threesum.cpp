#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin>> n >> x;

    vector<pair<long long, int>> vals;
    vals.reserve(n);

    for(int i = 1; i <= n; ++i){
        long long val;
        cin >> val;
        vals.emplace_back(val, i);
    }

    sort(vals.begin(), vals.end());

    for(int i = 0; i < n; i++){
        int left = i + 1;
        int right = n - 1;

        while (left < right){
            long long sum = vals[i].first + vals[left].first+vals[right].first;

            if(sum == x){
                vector<int> ans = {vals[i].second, vals[left].second, vals[right].second};
                sort(ans.begin(), ans.end());
                cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
                return 0;
            }
            else if (sum < x){
                ++left;
            }
            else {
                --right;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
