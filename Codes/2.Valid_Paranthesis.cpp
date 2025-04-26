
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 
// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            
            // Use stack
            stack<char> st;
            for (char ch : s) {
                // Add open bracket to stack
                if (ch == '(' || ch == '[' || ch == '{') {
                    st.push(ch);
                }else {
                    // IF closed bracket, check with stack paranthesis
                    if (st.empty()) return false;
                    if ((ch == ')' && st.top() != '(') || 
                        (ch == ']' && st.top() != '[') ||
                        (ch == '}' && st.top() != '{')) 
                        return false;
                    st.pop();
                }
            }
            return st.empty();
        }
    };

int main() {
    Solution sol;
    string s = "()[]";

    bool result = sol.isValid(s);

    if (result) {
        cout << "Valid parentheses" << endl;
    } else {
        cout << "Invalid parentheses" << endl;
    }

    return 0;
}
