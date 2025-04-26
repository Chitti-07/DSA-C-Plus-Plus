// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
// and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function, 
// but instead be stored inside the array nums1. To accommodate this, 
// nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
// and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

// Example 2:
// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    // Output: [1,2,2,3,5,6]
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int ind = m+n-1;
        int m1 = m-1;
        int n1 = n-1;

        // Iterate from the last elements of the array and compare each number and place it in the last position of the array
        while(m1 >= 0 && n1 >= 0) {
            if (nums1[m1] >= nums2[n1]) {
                nums1[ind--] = nums1[m1--];
            }else {
                nums1[ind--] = nums2[n1--];
            }
        }

        while (n1 >= 0) {
            nums1[ind--] = nums2[n1--];
        }
    }
};


int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    
    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}