// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:
// Input: nums = [2,2,1]
// Output: 1

// Example 2:
// Input: nums = [4,1,2,1,2]
// Output: 4

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};


int main() {
    Solution sol;  // Create an instance of the Solution class

    vector<int> nums = {4, 1, 2, 1, 2}; // Example input

    int uniqueNumber = sol.singleNumber(nums); // Call the function

    cout << "Single Number: " << uniqueNumber << endl; // Print result

    return 0;
}
