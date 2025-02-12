/*Median of two sorted arrays, nums1 and nums2.
Median - Middle value in a sorted list of numbers.
*/

#include <iostream>
#include <vector>
#include <climits>

//Solve using the binary search approach.

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int i = low + (high - low) / 2;  // Partition index for nums1
            int j = (m + n + 1) / 2 - i;    // Partition index for nums2

            // Handling edge cases
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];

            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];

            // If correct partition is found
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 0) {  // Even length case
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {  // Odd length case
                    return max(maxLeft1, maxLeft2);
                }
            }
            else if (maxLeft1 > minRight2) {
                high = i - 1;  // Move partition left
            }
            else {
                low = i + 1;   // Move partition right
            }
        }

        throw invalid_argument("Input arrays are not sorted!"); // Should never reach here
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.00000

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Median: " << solution.findMedianSortedArrays(nums3, nums4) << endl; // Output: 2.50000

    return 0;
}
