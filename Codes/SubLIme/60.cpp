// Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by 
// rotating mat in 90-degree increments, or false otherwise.

 

// Example 1:


// Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
// Output: true
// Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
// Example 2:


// Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
// Output: false
// Explanation: It is impossible to make mat equal to target by rotating 



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
		for (int i = 0; i < mat.size(); i++) {
    		for (int j = 0; j < mat[i].size(); j++) {
    			if (mat[i][j] != target[i][j]) {
    				return false;
   				}
    		}
    	}
    	return true;
	}


    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

    	for (int r = 0; r < 4; r++) {
    		vector<vector<int>>arr(mat.size(), vector<int>(mat[0].size()));
    		for (int i = 0; i < mat.size(); i++) {
    			for (int j = 0; j < mat[i].size(); j++) {
    				arr[i][j] = mat[j][mat.size()-i-1];
    			}
    		}

    		if (isEqual(arr, target)) {
    			return true;
    		}
    		mat = arr;
    	}
    	return false;
    }


};

int main() {
    Solution sol;
    
    vector<vector<int>> mat = {
        {0, 1},
        {1, 0}
    };
    
    vector<vector<int>> target = {
        {1, 0},
        {0, 1}
    };

    bool result = sol.findRotation(mat, target);
    cout << (result ? "Matrix can be rotated to match target" : "Matrix cannot be rotated to match target") << endl;

    return 0;
}
