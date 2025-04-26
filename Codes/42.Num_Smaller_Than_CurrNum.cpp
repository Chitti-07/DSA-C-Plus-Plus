// Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. 
// That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
// Return the answer in an array.

// Example 1:
// Input: nums = [8,1,2,2,3]
// Output: [4,0,1,1,3]
// Explanation: 
// For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
// For nums[1]=1 does not exist any smaller number than it.
// For nums[2]=2 there exist one smaller number than it (1). 
// For nums[3]=2 there exist one smaller number than it (1). 
// For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).

// Example 2:
// Input: nums = [6,5,4,8]
// Output: [2,1,0,3]

// Example 3:
// Input: nums = [7,7,7,7]
// Output: [0,0,0,0]


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        vector<int> res(nums.size(), 0);
        // Brute Force -> O(n^2)
        // for (int i = 0; i < nums.size(); i++) {
        //     int s = 0;
        //     for (int j = 0; j < nums.size(); j++) {
        //         if (i != j && nums[i] > nums[j]) {
        //             res[i]++;
        //         }
        //     }
        // }
        // return res;
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    vector<int> nums = {8, 1, 2, 2, 3}; // Example input
    vector<int> result = solution.smallerNumbersThanCurrent(nums);

    cout << "Result: ";
    printVector(result);

    return 0;
}
