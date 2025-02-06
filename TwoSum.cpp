/*given an array of integers 'nums' and an integer 'target'
 We need to find two indices in nums such that the numbers at those indices sum up to target
We cannot use the same element twice, and we are guaranteed that there is exactly one solution.

Example: If nums = [2,7,11,15] and target = 9, the output is [0,1] because nums[0] + nums[1] = 2 + 7 = 9.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*A simple way to solve is by using Brute force approach(using two nested loops(O(n*2))). An optimized 
approach is the use of Hash-Maps(unordered_map in C++):
 1. Traverse the array once.
 2.For each number nums[i], check if target - nums[i] is present in the map.
 3. If it is, return the indices [hash_map[complement], i].
    Otherwise, store nums[i] in the hash map with its index.

    NB:This ensures that we only traverse the array once, making the time complexity O(n).

*/

vector<int> twoSum(vector<int>&nums, int target){
    unordered_map<int, int> numMap; //Stores number and its indexx
    for(int i = 0; i <nums.size(); i++){
      int complement = target - nums[i];
      if(numMap.find(complement) != numMap.end()){
          return {numMap[complement], i}; //Found the pair.
      }

      numMap[nums[i]] = i; //Store the number and its index.
    }
    return{}; //No pair found.
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> result = twoSum(nums, target);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}

