#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    multiset<int> towers;
    for (int i = 0; i < n; i++)
    {
        int cube;
        cin >> cube;

        auto it = towers.upper_bound(cube); // find tower top > cube
        if (it != towers.end())
        {
            towers.erase(it); // reuse this tower
        }
        towers.insert(cube); // update with current cube
    }

    cout << towers.size() << "\n";
    return 0;
}
