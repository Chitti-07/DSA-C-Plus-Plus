// You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:
// Characters ('a' to 'i') are represented by ('1' to '9') respectively.
// Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
// Return the string formed after mapping.
// The test cases are generated so that a unique mapping will always exist.

// Example 1:
// Input: s = "10#11#12"
// Output: "jkab"
// Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

// Example 2:
// Input: s = "1326#"
// Output: "acz"


#include <iostream>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] == '#') {
                res += ((s[i-2]-'0')*10 + (s[i-1]-'0')-1) + 'a';
                cout << (s[i-2]-'0')*10 + (s[i-1]-'0') << endl;
                i -= 2;
            }else { 
                res += (s[i]-'0'-1) + 'a';
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {
    Solution solution;

    string s = "10#11#12"; // Example input
    string result = solution.freqAlphabets(s);

    cout << "Decoded String: " << result << endl;

    return 0;
}
