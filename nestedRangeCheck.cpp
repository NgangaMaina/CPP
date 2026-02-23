#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int l, r, idx;
};

bool cmp(const Interval &a, const Interval &b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        intervals[i] = {x, y, i};
    }
    
    sort(intervals.begin(), intervals.end(), cmp);
    
    vector<int> contains_other(n, 0);
    vector<int> contained_by_other(n, 0);
    
    // Forward pass: Compute if contained by other
    long long max_right = LLONG_MIN;
    for (const auto &inv : intervals) {
        if (max_right >= inv.r) {
            contained_by_other[inv.idx] = 1;
        }
        max_right = max(max_right, (long long)inv.r);
    }
    
    // Backward pass: Compute if contains other
    long long min_right = LLONG_MAX;
    for (int i = n - 1; i >= 0; i--) {
        const auto &inv = intervals[i];
        if (min_right <= inv.r) {
            contains_other[inv.idx] = 1;
        }
        min_right = min(min_right, (long long)inv.r);
    }
    
    // Output first line: contains other
    for (int i = 0; i < n; i++) {
        cout << contains_other[i];
        if (i < n - 1) cout << " ";
        else cout << "\n";
    }
    
    // Output second line: contained by other
    for (int i = 0; i < n; i++) {
        cout << contained_by_other[i];
        if (i < n - 1) cout << " ";
        else cout << "\n";
    }
    
    return 0;
}
