// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, 
// then reverse the first k characters and leave the other as original.

// Example 1:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"

// Example 2:
// Input: s = "abcd", k = 2
// Output: "bacd"


#include <iostream>
using namespace std;

class Solution {
public:

    void Reverse(string& s, int st, int en) {
        while (st < en) {
            char temp = s[st];
            s[st] = s[en];
            s[en] = temp;
            st++;
            en--;
        }
        //cout << "Original String: " << s << endl;
    }
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i+=(2*k)) {
            int st = i;
            int en = i + k < s.length() ? i + k : s.length()-1;

            Reverse(s, st, en-1);
        }
        return s;
    }
};

int main() {
    Solution solution;

    string s = "chitti Babu";
    int k = 2;

    cout << "Original String: " << s << endl;
    string result = solution.reverseStr(s, k);

    cout << "Reversed String: " << result << endl;

    return 0;
}
