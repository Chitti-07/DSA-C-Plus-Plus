// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Brute Force appeoach -> Time limit will exceeded for larger inputs
        // for (int i = 0; i < s.length(); i++) {
        //     for (int j = 0; j < t.length(); j++) {
        //         if (s[i] == t[j]) {
        //             s[i] = '.';
        //             t[j] = '.';
        //             break;
        //         }
        //     }
        // }
        // cout << s << " " << t << endl;
        // for (int i = 0, j = 0; s[i] || t[j]; i++, j++) {
        //     if (s[i] != '.' || t[j] != '.') {
        //         return false;
        //     }
        // }
        // return true;

        // Using hash maps

        unordered_map <char, int>mp;
        for (char ch : s) {
            mp[ch]++;
        }

        for (char ch : t) {
            mp[ch]--;
        }

        for (auto &var : mp) {
            if (var.second != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    
    string s = "a";
    string t = "ab";

    bool result = solution.isAnagram(s, t);
    //cout << s << " " << t << endl;
    cout << "Are \"" << s << "\" and \"" << t << "\" anagrams? " 
         << (result ? "Yes" : "No") << endl;

    return 0;
}
