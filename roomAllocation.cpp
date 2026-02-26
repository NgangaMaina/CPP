#include <bits/stdc++.h>
using namespace std;

struct Customer {
    int arr, dep, idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Customer> customers(n);
    for(int i = 0; i < n; i++) {
        cin >> customers[i].arr >> customers[i].dep;
        customers[i].idx = i;
    }

    //Sort customers by arrival day(ascendng)
    sort(customers.begin(), customers.end(), [](const Customer& a, const Customer& b){
            return a.arr < b.arr;
            });

    //Min-heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> assignment(n);
    int max_rooms = 0;

    for(const auto& c : customers) {
        int room = -1;
        if(!pq.empty() && pq.top().first < c.arr) {
            //Room that becomes free earliest is available
            auto[end_time, r] = pq.top();
            pq.pop();
            room = r;
        }

        if(room != -1) {
            //Reuse existing room
            assignment[c.idx] = room;
            pq.push({c.dep, room});
        }else {
            //Open new room
            ++max_rooms;
            assignment[c.idx] = max_rooms;
            pq.push({c.dep, max_rooms});
        }
    }

    cout << max_rooms << '\n';
    for(int i = 0; i < n; i++){
        cout << assignment[i] << (i + 1 < n ? " " : "\n");
    }
    return 0;
}
