#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    size_t operator() (long long x) const {
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9LL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebLL;
        return x ^ (x >> 31);
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x;
    cin >> n >> x;

    //Unordered map for O(1) lookups (Maps prefix sum)
    unordered_map<long long, long long, custom_hash> freq;

    //Seed with 0 to handle subarrays starting at index 0
    freq[0] = 1;
    long long prefix = 0;
    long long count = 0;

    for(int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        prefix += a;

        long long target = prefix - x;

        if(freq.count(target)) {
            count += freq[target];
        }

        freq[prefix]++;
    }
    
    cout << count << "\n";
    return 0;
        

}
