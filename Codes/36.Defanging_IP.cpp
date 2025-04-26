// Given a valid (IPv4) IP address, return a defanged version of that IP address.
// A defanged IP address replaces every period "." with "[.]".

// Example 1:

// Input: address = "1.1.1.1"
// Output: "1[.]1[.]1[.]1"
// Example 2:

// Input: address = "255.100.50.0"
// Output: "255[.]100[.]50[.]0"

#include <iostream>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (char ch : address) {
            if (ch == '.') {
                res += "[.]";
            }else {
                res += ch;
            }
        }
        return res;
    }
};


int main() {
    Solution solution;

    string address = "192.168.1.1"; // Example input
    string result = solution.defangIPaddr(address);

    cout << "Defanged IP Address: " << result << endl;

    return 0;
}
