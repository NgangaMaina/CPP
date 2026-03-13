#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //Coordinate compression
    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for(int i = 0; i < n; i++){
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }
    int m = vals.size();

    //Sliding window 
    vector<int> freq(m + 1, 0);
    long long ans = 0;
    int left = 0;
    int distinct = 0;

    for(int right = 0; right  < n; ++right){
        int val = a[right];
        freq[val]++;
        if (freq[val] == 1) ++distinct;

        //Shrink from left until we have <=k distinct
        while(distinct > k && left <= right) {
            int vleft = a[left];
            freq[vleft]--;
            if(freq[vleft] == 0) --distinct;
            ++left;
        }

        ans += (right - left + 1LL);
    }

    cout << ans << "\n";
    return 0;
}
