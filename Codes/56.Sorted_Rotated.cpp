// Given an array nums, return true if the array was originally sorted in non-decreasing order, 
// then rotated some number of positions (including zero). Otherwise, return false.
// There may be duplicates in the original array.
// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.
// 	length] for every valid index i.

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].
// Example 2:

// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.
// Example 3:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.
// You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.



#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool check(vector<int>& nums) {
        int pivoit = 0;
        bool isRotated = true;
        for (int i = 1; i < nums.size(); i++) {
        	if (nums[i] < nums[i-1]) {
                pivoit = i;
                isRotated = false;
            }
        }

        if (isRotated) {
            return true;
        }

        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            res[i] = nums[(pivoit+i)%nums.size()];
        }

        // for (int i = 0; i < nums.size(); i++) {
        //     cout << res[i];
        // }

        for (int i = 0; i < nums.size()-1; i++) {
            if (res[i] > res[i+1]) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {2,1,3,4};

    bool result = sol.check(nums);
    cout << (result ? "True" : "False") << endl;

    return 0;
}
