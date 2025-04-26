// Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

// Example 1:

// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
// Output: [15]
// Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
// Example 2:

// Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
// Output: [12]
// Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
// Example 3:

// Input: matrix = [[7,8],[1,2]]
// Output: [7]
// Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    	vector<int> res;
        int min, max;
        int col;
        int i, j;
        for (i = 0; i < matrix.size(); i++) {
        	min = matrix[i][0];
            col = 0;
        	for (j = 0; j < matrix[0].size(); j++) {
        		if (matrix[i][j] < min) {
                    min = matrix[i][j];
        			col = j;
        		}
        	}
        	max = matrix[i][col];
        	for (j = 0; j < matrix.size(); j++) {
        		if (matrix[j][col] > max) {
                    break;
        		}
        	}
            if (j == matrix.size()) {
                res.push_back(matrix[i][col]);
            }
        }
        return res;
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

    vector<vector<int>> matrix = {
        {3, 7, 8},
        {9, 11, 13},
        {15, 16, 17}
    }; // Example input

    vector<int> result = solution.luckyNumbers(matrix);

    cout << "Lucky Numbers: ";
    printVector(result);

    return 0;
}
