// In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a 
// new one with a different size r x c keeping its original data.
// You are given an m x n matrix mat and two integers r and c representing the number of rows and 
// the number of columns of the wanted reshaped matrix.
// The reshaped matrix should be filled with all the elements of the original matrix in the 
// same row-traversing order as they were.
// If the reshape operation with given parameters is possible and legal, 
// output the new reshaped matrix; Otherwise, output the original matrix.

// Example 1:
// Input: mat = [[1,2],[3,4]], r = 1, c = 4
// Output: [[1,2,3,4]]

// Example 2:
// Input: mat = [[1,2],[3,4]], r = 2, c = 4
// Output: [[1,2],[3,4]]


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r*c) return mat;
        vector<vector<int>> res(r, vector<int>(c));
        int row = 0, col = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                res[row][col++] = mat[i][j];
                if (col > c) {
                    col = 0;
                    row++;
                }
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

    vector<vector<int>> mat = {
        {1, 2},
        {3, 4}
    };
    // cout << mat.size();
    int r = 1, c = 4;

    vector<vector<int>> result = solution.matrixReshape(mat, r, c);

    cout << "Reshaped Matrix:\n";
    printMatrix(result);

    return 0;
}

