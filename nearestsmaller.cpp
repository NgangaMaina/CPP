#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n + 1);       //1-based array for values
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> ans(n + 1, 0);     //1-base result Array
    stack<int> st;      //Stack for monotnic increasing value

    for(int i = 1; i <= n; ++i){
    //Pop elements that are not strictly smaller than current
    while (!st.empty() && a[st.top()] >= a[i]) {
        st.pop();
    }

    //Set answer: 0 if no smaller, otherwise pop
    if(st.empty()) {
        ans[i] = 0;
    }else {
        ans[i] =  st.top();
    }

    //Push current index
    st.push(i);
    }    

    //Output
    for (int i = 1; i <= n; ++i) {
        cout << ans[i];
        if (i < n) cout << " "; 
    }
    cout << endl;
    return 0;
}

