// The array-form of an integer num is an array representing its digits in left to right order.
// For example, for num = 1321, the array form is [1,3,2,1].
// Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

// Example 1:
// Input: num = [1,2,0,0], k = 34
// Output: [1,2,3,4]
// Explanation: 1200 + 34 = 1234

// Example 2:
// Input: num = [2,7,4], k = 181
// Output: [4,5,5]
// Explanation: 274 + 181 = 455

// Example 3:
// Input: num = [2,1,5], k = 806
// Output: [1,0,2,1]
// Explanation: 215 + 806 = 1021

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int i;
        for (i = num.size()-1; i >= 0 || k > 0; i--) {
            k += num[i];
            res.push_back(k%10);
            k /= 10;
        }
        reverse(res.begin(), res.end());
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

    vector<int> num = {2,1,5, 6}; 
    int k = 9999; // Example input
    
    vector<int> result = solution.addToArrayForm(num, k);

    cout << "Result: ";
    printVector(result);

    return 0;
}
