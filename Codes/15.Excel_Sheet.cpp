// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...
 

// Example 1:
// Input: columnNumber = 1
// Output: "A"

// Example 2:
// Input: columnNumber = 28
// Output: "AB"

// Example 3:
// Input: columnNumber = 701
// Output: "ZY"


#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        if (columnNumber < 0) return res;
        while (columnNumber > 0) {
            columnNumber--;
            char c = 'A' + columnNumber % 26;
            res.push_back(c);
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;  // Create an instance of Solution class

    int columnNumber = 28; // Example input (should return "AB")

    string columnTitle = sol.convertToTitle(columnNumber); // Call function

    cout << "Column Title: " << columnTitle << endl; // Print result

    return 0;
}
