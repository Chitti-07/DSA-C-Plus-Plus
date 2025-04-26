// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            
            // Brute Force
            // For each element search for other element that adds to target
            // for (int i = 0; i < nums.size(); i++) {
            //     for (int j = i + 1; j < nums.size(); j++) {
            //         if (nums[i] + nums[j] == target) {
            //             return {i, j};
            //         }
            //     }
            // }

            // Using hash table
            unordered_map <int, int> mp;
            int difference = 0; // USed to store the difference b/t target and current number
            for (int i = 0; i < nums.size(); i++) {
                difference = target - nums[i];
                if (mp.find(difference) != mp.end()) { // Search in hash table for the difference
                    return {mp[difference], i}; // If the difference is present, return the indecies
                }
                mp[nums[i]] = i; // If diff is not present add the current number to hash table
            }
            return {-1, -1};
        }
    };

    int main() {
        Solution sol;
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
    
        vector<int> result = sol.twoSum(nums, target);
    
        if (!result.empty()) {
            cout << "Indices: " << result[0] << ", " << result[1] << endl;
        } else {
            cout << "No solution found" << endl;
        }
    
        return 0;
    }