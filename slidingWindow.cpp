#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
//Maintain a window [left, right] with all distinct elements
long long countDistinctSubarrays(vector<int>& arr){
    int n = arr.size();
    long long count = 0;

    //Unordered set for O(1) average insert/delete/lookup (Tracks the elements currently in the window)
    unordered_set<int> window;
    int left = 0; //Left ptr of sliding winndow

    //Two-ptr iteration
    for (int right = 0; right < n; right++){
    //While loop for window adjustments
        while (window.count(arr[right]) > 0){
            window.erase(arr[left]);
            left++;
        }

        //Add current element to window
        window.insert(arr[right]);

       //Count subarrays ending at right
        count += (right - left + 1);
    
    }
    return count;

}

int main() {
    //Fast I/O Optimization (Disabling C stdio synch for faster I/O)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    //Vector for a dynamic array
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long result = countDistinctSubarrays(arr);
    cout << result << endl;
    
    return 0;
}
