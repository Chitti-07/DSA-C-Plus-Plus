// Given an array nums containing n distinct numbers in the range [0, n], 
// return the only number in the range that is missing from the array.

// Example 1:
// Input: nums = [3,0,1]
// Output: 2

// Explanation:
// n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
// 2 is the missing number in the range since it does not appear in nums.

// Example 2:
// Input: nums = [0,1]
// Output: 2

// Explanation:
// n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 
// 2 is the missing number in the range since it does not appear in nums.

// Example 3:
// Input: nums = [9,6,4,2,3,5,7,0,1]
// Output: 8

// Explanation:
// n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 
// 8 is the missing number in the range since it does not appear in nums.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Brute Force --> but for sorting it is taking O(n^2)
        // sort(nums.begin(), nums.end());
        // int i;
        // for (i = 0; i < nums.size(); i++) {
        //     if (nums[i] != i) {
        //         return i;
        //     }
        // }
        // return i;

        // We can use the sum of N whole numbers, as the array starts for [0-n]
        // int currSum = 0;
        // for (int num : nums) {
        //     currSum += num;
        // }
        // int n = nums.size();
        // int Nsum = n * (n + 1)/2;
        // return Nsum - currSum;

        // We can use the XOR to get the missing number -> n ^ 0 = n, 0 ^ 1 ^ 2 != 0 ^ 1 ^ 2 ^ 3 ==> 2

        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }

        for (int i = 1; i <= nums.size(); i++) {
            ans ^= i;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {3, 0, 1, 2, 5, 7, 4}; // Example input

    int missingNum = solution.missingNumber(nums);
    cout << "Missing Number: " << missingNum << endl;

    return 0;
}
