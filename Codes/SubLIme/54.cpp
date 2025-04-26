// You are given a string s of even length. Split this string into two halves of equal lengths, 
// and let a be the first half and b be the second half.
// Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U').
// Notice that s contains uppercase and lowercase letters.
// Return true if a and b are alike. Otherwise, return false.

 

// Example 1:

// Input: s = "book"
// Output: true
// Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
// Example 2:

// Input: s = "textbook"
// Output: false
// Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
// Notice that the vowel o is counted twice.


#include <iostream>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
    	string a = "";
    	string b = "";
    	int Vc = 0;
    	for (int i = 0; i < s.length()/2; i++) {
    		char ch = tolower(s[i]);
    		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
    			Vc++;
    		}
    		a += s[i];

    	}   

    	for (int i = s.length()/2; i < s[i]; i++) {
    		char ch = tolower(s[i]);
    		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
    			Vc--;
    		}
    		b += s[i];
    	}
    	return Vc == 0;

    }
};

int main() {
    Solution sol;
    string s = "boook";

    bool result = sol.halvesAreAlike(s);
    cout << (result ? "True" : "False") << endl;

    return 0;
}
