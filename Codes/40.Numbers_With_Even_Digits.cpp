// Given an array nums of integers, return how many of them contain an even number of digits.

// Example 1:
// Input: nums = [12,345,2,6,7896]
// Output: 2
// Explanation: 
// 12 contains 2 digits (even number of digits). 
// 345 contains 3 digits (odd number of digits). 
// 2 contains 1 digit (odd number of digits). 
// 6 contains 1 digit (odd number of digits). 
// 7896 contains 4 digits (even number of digits). 
// Therefore only 12 and 7896 contain an even number of digits.

// Example 2:
// Input: nums = [555,901,482,1771]
// Output: 1 
// Explanation: 
// Only 1771 contains an even number of digits.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0, even = 0;
        for (int num : nums) {
            count = 0;
            while (num) {
                count++;
                num /= 10;
            }
            if (count % 2 == 0) {
                even++;
            }
        }
        return even;
    }
};


int main() {
    Solution solution;

    vector<int> nums = {12, 345, 2, 6, 7896}; // Example input
    int result = solution.findNumbers(nums);

    cout << "Count of numbers with even number of digits: " << result << endl;

    return 0;
}

