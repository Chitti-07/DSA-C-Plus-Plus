#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findElement(int row, int col) {
        int ele = 1;
        //if (row == 0 && col == 0) return ele;
        for (int i = 0; i < col; i++) {
            ele = ele * (row - i);
            ele = ele / (i + 1);
        }
        return ele;
    }

    vector<int> generateHelper(int row) {
        int res = 1;
        vector<int> ans;
        ans.push_back(1);

        // We are following the binomial coefficient --> nCr
        for (int col = 1; col <= row; col++) {
            res = res * (row - col + 1);
            res = res / col;
            ans.push_back(res);
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int row = 0; row < numRows; row++) {
            ans.push_back(generateHelper(row));
        }
        return ans;
    }
};

int main() {
    int numRows = 5;
    Solution sol;
    vector<vector<int>> result = sol.generate(numRows);
    
    cout << "Pascal's Triangle:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "element at 2 2 " << sol.findElement(4, 2);
    
    return 0;
}