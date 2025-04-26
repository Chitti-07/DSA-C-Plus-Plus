// Given an integer array nums, return true if any value appears at least twice in the array, 
// and return false if every element is distinct.

// Example 1:
// Input: nums = [1,2,3,1]
// Output: true

// Explanation:
// The element 1 occurs at the indices 0 and 3.

// Example 2:
// Input: nums = [1,2,3,4]
// Output: false

// Explanation:
// All elements are distinct.

// Example 3:
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // Brute force  -> But it dosn't work for the large inputs(Time limit exceeded)

        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (nums[i] == nums[j]) return true;
        //     }
        // }
        // return false;

        // Using Hash Maps
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        for (auto &var : mp) {
            if (var.second > 1) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    Solution sol;  // Create an instance of the Solution class

    vector<int> nums1 = {1, 2, 3, 4, 5};  // No duplicates
    vector<int> nums2 = {1, 2, 3, 1};    // Contains duplicate (1)

    cout << "nums1 contains duplicate: " << (sol.containsDuplicate(nums1) ? "Yes" : "No") << endl;
    cout << "nums2 contains duplicate: " << (sol.containsDuplicate(nums2) ? "Yes" : "No") << endl;

    return 0;
}
