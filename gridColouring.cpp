#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    //Vector to hold the grid
    vector<string> original(n);
    for(int i = 0; i < n; ++i) {
        cin >> original[i];
    }

    vector<string> result(n, string(m, ' '));

    //Greedy Pass: Traverse in exactly the order that guarantees <=2 previous neighbours.
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j){
            char orig = original[i][j];

            char left = (j > 0 ? result[i][j - 1] : '\0');
            char up = (i > 0 ? result[i - 1][j] : '\0');

            for(char c = 'A'; c <= 'D'; ++c){
                if(c != orig &&
                  (j == 0 || c != left) &&
                  (i == 0 || c != up)) {
                    result[i][j] = c;
                    break;
                }
            }
        }
    }

    for(const auto& row : result) {
        cout << row << '\n';
    }

    return 0;

}
