 #include <iostream>
#include <set>
#include <vector>
using namespace std;


int main() {
    int x, n;
    cin >> x >> n;

    //Store positions of traffic lights (Including boundaries)
    set<int> lights;
    lights.insert(0);
    lights.insert(x);

    //Lengths of all passages
    multiset<int> passages;
    passages.insert(x);


    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        //find the gap where this light will be added
        auto it = lights.upper_bound(p);
        int right = *it;
        int left = *(--it);

        //Remove the old passage length
        passages.erase(passages.find(right - left));

        passages.insert(p - left);
        passages.insert(right - p);

        lights.insert(p);

        cout << *passages.rbegin() << " ";

    }
    cout << endl;
    return 0;


}
