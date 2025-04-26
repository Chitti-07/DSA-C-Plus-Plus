// Given a square matrix mat, return the sum of the matrix diagonals.

// Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

 

// Example 1:


// Input: mat = [[1,2,3],
//               [4,5,6],
//               [7,8,9]]
// Output: 25
// Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
// Notice that element mat[1][1] = 5 is counted only once.
// Example 2:

// Input: mat = [[1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1]]
// Output: 8
// Example 3:

// Input: mat = [[5]]
// Output: 5


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int sum = 0;
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		if (i == j || (i + j == m-1)) {
        			sum += mat[i][j];
        		}
        	}
        }

        if (m % 2 != 0) {
        	sum -= mat[m/2][n/2];
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int sum = sol.diagonalSum(mat);
    cout << "Diagonal Sum: " << sum << endl;

    return 0;
}
