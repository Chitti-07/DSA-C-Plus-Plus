// Given two integer arrays nums1 and nums2, return an array of their intersection. 
// Each element in the result must be unique and you may return the result in any order.

// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]

// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    vector<int> RemoveDuplicates(vector<int>& nums1) {

        vector<int> uniqArr;
        for (int i = 0; i < nums1.size(); i++) {
            bool found = false;
            for (int j = i+1; j < nums1.size(); j++) {
                if (nums1[i] == nums1[j]) {
                    found = true;
                    break;
                }
            }
            if (found) {
                uniqArr.push_back(nums1[i]);
            }
        }
        return uniqArr.empty() ? nums1 : uniqArr;
    }

    void PrintArray(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Brute Force -> 1.Remove Duplicates from individual arrays, and finding the intersecting elements

        vector<int> res;
        // Removing duplicates
        // nums1 = RemoveDuplicates(nums1);
        // nums2 = RemoveDuplicates(nums2);

        // PrintArray(nums1);
        // PrintArray(nums2);
    
        // for (int i = 0; i < nums1.size(); i++) {
        //     for (int j = 0; j < nums2.size(); j++) {
        //         if (nums1[i] == nums2[j]) {
        //             res.push_back(nums1[i]);
        //             break;
        //         }
        //     }
        // }
        // return res;

        // Optimised way -> use unordered set which stores unique elements, compare it with other array elements
        unordered_set<int> hashSet;
        for (int i = 0; i < nums1.size(); i++) {
            hashSet.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (hashSet.find(nums2[i]) != hashSet.end()) {
                res.push_back(nums2[i]);
                hashSet.erase(nums2[i]);
            }
        }
        return res;
        
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> result = solution.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
