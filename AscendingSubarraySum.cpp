#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0], currentSum = nums[0];

        for (size_t i = 1; i<nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                currentSum += nums[i];
            }else{
                maxSum = max(maxSum, currentSum);
                currentSum = nums[i];
            }
        }
        return max(maxSum, currentSum);
    }
        int main(){
            vector<int> nums = {10, 20, 30, 5, 10, 50};
            cout <<"Max ascending Subarray Sum: " <<maxAscendingSum(nums) <<endl;
            return 0;
        }

};