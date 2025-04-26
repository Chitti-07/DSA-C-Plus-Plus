// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average 
// value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

// Example 1:
// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:
// Input: nums = [5], k = 1
// Output: 5.00000

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double MaxAvg = 0, sum = 0, CurrAvg = 0;
        int WinS = 0, winE = 0;
        while (winE != nums.size()-1) {
            sum += nums[winE++];
            if (winE >= k-1) {

                CurrAvg = sum/k;
                MaxAvg = max(MaxAvg, CurrAvg);
                sum -= nums[WinS];
                WinS++;
            }
        }
        return MaxAvg;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = solution.findMaxAverage(nums, k);

    cout << "Maximum Average Subarray: " << result << endl;

    return 0;
}
