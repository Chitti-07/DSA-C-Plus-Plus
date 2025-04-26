// Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

// A string is represented by an array if the array elements concatenated in order forms the string.

 

// Example 1:

// Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
// Output: true
// Explanation:
// word1 represents string "ab" + "c" -> "abc"
// word2 represents string "a" + "bc" -> "abc"
// The strings are the same, so return true.
// Example 2:

// Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
// Output: false
// Example 3:

// Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
// Output: true

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
		string s1 = "";
		string s2 = "";

		for (auto ch : word1) {
			s1 += ch;
		}       

		for (auto ch : word2) {
			s2 += ch;
		}

		return s1 == s2;
    }
};

int main() {
    Solution sol;
    vector<string> word1 = {"ab", "c"};
    vector<string> word2 = {"a", "c"};

    bool result = sol.arrayStringsAreEqual(word1, word2);
    cout << (result ? "True" : "False") << endl;

    return 0;
}
