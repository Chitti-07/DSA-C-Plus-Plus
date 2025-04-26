

// Given an array nums, you can perform the following operation any number of times:
// Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
// Replace the pair with their sum.
// Return the minimum number of operations needed to make the array non-decreasing.
// An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 
// Example 1:
// Input: nums = [5,2,3,1]
// Output: 2

// Explanation:

// The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
// The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
// The array nums became non-decreasing in two operations.

// Example 2:
// Input: nums = [1,2,2]
// Output: 0

// Explanation:

// The array nums is already sorted.


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

	bool isSorted(vector<int>& nums) {
		for (int i = 0; i < nums.size()-1; i++) {
			if(nums[i] > nums[i+1]) {
				return false;
			}
		}
		return true;
	}


	int helper(vector<int>& nums, int cnt) {
		if (isSorted(nums)) {
    		return cnt;
    	}

    	vector<int> res;
    	vector<pair<int, int>>sums;
		int s = 0;
		int e = s+1;
		for (int i = 0; i < nums.size()-1; i++) {
			sums.push_back({i, nums[i] + nums[i+1]});
		}

		int min = 99999, pos = -1;
		for (auto &var : sums) {
			if (var.second < min) {
				min = var.second;
				pos = var.first;
			}
		}

		//cout << "Min -> " << min << " " << "Pos -> " << pos << endl;
 
		// for (auto& var: sums) {
  //           cout << var.first << " " << var.second << endl;
  //       }
  //       cout << endl;

		if (pos == -1) return cnt;

		int i = 0; 
		while (i < nums.size()) {
			if (i == pos) {
				res.push_back(min);
				i += 2;
			}else {
				res.push_back(nums[i++]);
			}
		}
		nums = res;
    	cnt++;
    	for (int i = 0; i < nums.size(); i++) 
        	cout << nums[i] << " ";
        cout << endl;
    	return helper(nums, cnt);
	}
    int minimumPairRemoval(vector<int>& nums) {
    	
    	return helper(nums, 0);
    }
};

int main() {
    Solution sol;     //0,1,2, 3,4, 5,6,7,8,9,10
    vector<int> nums = {2,2,-1,3,-2,2,1,1,1,0,-1};  // Example input
    int result = sol.minimumPairRemoval(nums);
    cout << "Minimum pair removal: " << result << endl;
    return 0;
}
