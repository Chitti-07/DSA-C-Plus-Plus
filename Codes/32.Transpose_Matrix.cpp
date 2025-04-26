// Given a 2D integer array matrix, return the transpose of matrix.
// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]

// Example 2:
// Input: matrix = [[1,2,3],
                  //[4,5,6]]
// Output: [[1,4],[2,5],[3,6]]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // In-Place Transpose for NxN 
        // for (int i = 0; i < n; i++) {
        //     for (int j = i+1; j < n; j++) {
        //         int temp = matrix[i][j];
        //         matrix[i][j] = matrix[j][i];
        //         matrix[j][i] = temp;
        //     }
        // }
        //return matrix;

        vector<vector<int>>res(m, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> result = solution.transpose(matrix);

    cout << "Transposed Matrix:\n";
    printMatrix(result);

    return 0;
}
