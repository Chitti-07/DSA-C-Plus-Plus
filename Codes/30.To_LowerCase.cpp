// Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

// Example 1:
// Input: s = "Hello"
// Output: "hello"

// Example 2:
// Input: s = "here"
// Output: "here"

// Example 3:
// Input: s = "LOVELY"
// Output: "lovely"


#include <iostream>
using namespace std;

class Solution {
public:
    string toLowerCase(string& s) {
        for (int i = 0; s[i]; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
        }
        return s;
    }
};

int main() {
    Solution solution;

    string s = "Hello, WORLD!";
    string result = solution.toLowerCase(s);

    cout << "Lowercase String: " << result << endl;

    return 0;
}
