// Given a positive integer n, write a function that returns the number of set bits in its binary 
// representation (also known as the Hamming weight).

// Example 1:
// Input: n = 11
// Output: 3

// Explanation:
// The input binary string 1011 has a total of three set bits.

// Example 2:
// Input: n = 128
// Output: 1

// Explanation:
// The input binary string 10000000 has a total of one set bit.

// Example 3:
// Input: n = 2147483645
// Output: 30

// Explanation:
// The input binary string 1111111111111111111111111111101 has a total of thirty set bits.



#include <iostream>
using namespace std;


class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            if (n & 1) {
                count++;
            }
            n = (unsigned) n >> 1;
        }
        return count;
    }
};


int main() {
    Solution sol;  // Create an instance of the Solution class

    int n = -1; // Example input (binary: 1011, should return 3)

    int count = sol.hammingWeight(n); // Call the function

    cout << "Hamming Weight: " << count << endl; // Print result

    return 0;
}
