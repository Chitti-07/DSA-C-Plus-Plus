// A pangram is a sentence where every letter of the English alphabet appears at least once.

// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, 
// or false otherwise.
 
// Example 1:
// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
// Explanation: sentence contains at least one of every letter of the English alphabet.

// Example 2:
// Input: sentence = "leetcode"
// Output: false




#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
    	vector<int>mp(26, 0);
    	for (char ch : sentence) {
    		mp[ch-'a']++;
    	}

    	for (auto &var : mp) {
    		if(var == 0) return false;
    	}
    	return true;
    }
};

int main() {
    Solution sol;
    string sentence = "thequickbrownfoxjumpsoverthelazydog";

    if (sol.checkIfPangram(sentence)) {
        cout << "The sentence is a pangram." << endl;
    } else {
        cout << "The sentence is not a pangram." << endl;
    }

    return 0;
}


