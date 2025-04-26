// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters 
// and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric 
// characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

// Example 3:
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, en = s.length() - 1;
        cout << en << endl;
        while (st < en) {
            if (!isalnum(s[st])) {st++; continue;}
            if (!isalnum(s[en])) {en--; continue;}

            if (tolower(s[st]) != tolower(s[en])) {
                return false;
            }else {
                st++;
                en--;
            }
        }
        return true;
    }
};


int main() {
    Solution sol;  // Create an instance of Solution class

    string str1 = "madam";  // Palindrome
    string str2 = "A man, a plan, a canal: Panama";  // Not a palindrome

    if (sol.isPalindrome(str1))
        cout << str1 << " is a palindrome" << endl;
    else
        cout << str1 << " is not a palindrome" << endl;

    if (sol.isPalindrome(str2))
        cout << str2 << " is a palindrome" << endl;
    else
        cout << str2 << " is not a palindrome" << endl;

    return 0;
}

