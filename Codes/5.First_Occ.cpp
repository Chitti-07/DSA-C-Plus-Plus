// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
// or -1 if needle is not part of haystack.
// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        // Brute force
        int i, j;
        // Iterate through the main string 
        for (i = 0; i < haystack.length(); i++) {
            // Iterate through the sub string and check if the sub string is present or not
            for (j = 0; j < needle.length(); j++) {
                if (haystack[i+j] != needle[j]) {
                    break;
                }
            }
            // If it is present then the j will be equal to sub string length
            if (j == needle.length()) {
                return i;
            }
        }
        return -1;
    }
};


int main() {
    Solution sol;
    string haystack = "hellheo";
    string needle = "heo";

    int index = sol.strStr(haystack, needle);

    cout << "Index: " << index << endl;

    return 0;
}
