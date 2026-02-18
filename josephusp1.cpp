#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    deque<int> circle;
    for(int i = 1; i <= n; i++) {
        circle.push_back(i);
    }

    vector<int> order;
    order.reserve(n);

    while(!circle.empty()) {
        //skip one(Move front to  back)
        int skipped = circle.front();
        circle.pop_front();
        circle.push_back(skipped);

        //eliminate the next
        if(!circle.empty()) {
            int eliminated = circle.front();
            circle.pop_front();
            order.push_back(eliminated);
        }
    }

    for (size_t i = 0; i < order.size(); ++i) {
        cout << order[i];
        if(i < order.size() - 1) cout << ' ';
    }

    cout << '\n';
    
    return 0;
}
