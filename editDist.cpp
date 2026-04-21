#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    string longer = s, shorter = t;
    if(s.size() < t.size()) {
        longer = t;
        shorter = s;
    }

    int len1 = longer.size();
    int len2 = shorter.size();

    vector<int> prev(len2 + 1);
    vector<int> curr(len2 + 1);

    for(int j = 0; j <= len2; ++j) {
        prev[j] = j;
    }

    for(int i = 1; i <= len1; ++i) {
        curr[0] = i;

        for(int j = 1; j <= len2; ++j) {
            int cost = (longer[i - 1] == shorter[j - 1] ? 0 : 1);
            curr[j] = min({prev[j - 1] + cost,
                           prev[j] + 1,
                           curr[j - 1] + 1
                    });
        }

        swap(prev, curr);
    }

    cout << prev[len2] << endl;
    return 0;
}
