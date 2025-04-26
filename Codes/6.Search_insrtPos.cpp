// Given a sorted array of distinct integers and a target value, 
// return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
            
        // For O(log n) we have to use binary search
        int mid;
        int s = 0, e = nums.size() - 1;
        while (s <= e) {

            // Mid element
            mid = s + (e - s)/2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (target > nums[mid]) { 
                s = mid + 1;
            }else {
                e = mid - 1;
            }
        }
        return s;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    int index = sol.searchInsert(nums, target);

    cout << "Index: " << index << endl;

    return 0;
}
