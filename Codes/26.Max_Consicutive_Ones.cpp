// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Example 1:
// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

// Example 2:
// Input: nums = [1,0,1,1,0,1]
// Output: 2


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int MaxLen = 0;
        int currLen = 0;
        for (int num : nums) {
            if (num == 0) {
                currLen = 0;
                continue;
            }
            currLen++;
            MaxLen = MaxLen > currLen ? MaxLen : currLen;
        }
        return MaxLen;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 1, 0, 1, 1, 1};

    int result = solution.findMaxConsecutiveOnes(nums);

    cout << "Maximum Consecutive Ones: " << result << endl;

    return 0;
}

