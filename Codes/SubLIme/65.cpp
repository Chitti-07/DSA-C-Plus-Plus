// Given an integer array nums, return all the triplets [nums[i], nums[j], 
// nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

 
// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i-1]) continue;

            int s = i+1, e = nums.size()-1;

            while (s < e) {

                int sum = nums[i]+nums[s]+nums[e];

                if (sum > 0){
                    e--;
                }
                else if(sum < 0) {
                    s++;
                }else {
                    ans.push_back({nums[i], nums[s], nums[e]});
                    while (s < e && nums[s] == nums[s+1]) s++;
                    while (s < e && nums[e] == nums[e-1]) e--;
                    s++;
                    e--;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = obj.threeSum(nums);

    cout << "Triplets that sum to 0:" << endl;
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
