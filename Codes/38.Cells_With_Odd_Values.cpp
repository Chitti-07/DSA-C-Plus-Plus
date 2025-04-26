// There is an m x n matrix that is initialized to all 0's. 
// There is also a 2D array indices where each indices[i] = [ri, ci] represents a 0-indexed location to 
// perform some increment operations on the matrix.
// For each location indices[i], do both of the following:
// Increment all the cells on row ri.
// Increment all the cells on column ci.
// Given m, n, and indices, return the number of odd-valued cells in the matrix after applying the increment to all locations in indices.

// Example 1:
// Input: m = 2, n = 3, indices = [[0,1],[1,1]]
// Output: 6
// Explanation: Initial matrix = [[0,0,0],[0,0,0]].
// After applying first increment it becomes [[1,2,1],[0,1,0]].
// The final matrix is [[1,3,1],[1,3,1]], which contains 6 odd numbers.

// Example 2:
// Input: m = 2, n = 2, indices = [[1,1],[0,0]]
// Output: 0
// Explanation: Final matrix = [[2,2],[2,2]]. There are no odd numbers in the final matrix.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (auto &row : indices) {
            int r = row[0];
            int c = row[1];

            // Increment Row
            for (int i = 0; i < res[0].size(); i++) {
                res[r][i]++;
            }

            // Increment Column
            for (int i = 0; i < res.size(); i++) {
                res[i][c]++;
            }
        }
        int odd = 0;
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[0].size(); j++) {
                if(res[i][j] % 2 != 0) {
                    odd++;
                }
            }
        }
        return odd;
    }
};


int main() {
    Solution solution;

    int m = 2, n = 3; // Example input dimensions
    vector<vector<int>> indices = {{0, 1}, {1, 1}}; // Example indices

    int result = solution.oddCells(m, n, indices);

    cout << "Number of cells with odd values: " << result << endl;

    return 0;
}
