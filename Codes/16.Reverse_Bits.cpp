// Reverse bits of a given 32 bits unsigned integer.
// Note:

// Note that in some languages, such as Java, there is no unsigned integer type. In this case, 
// both input and output will be given as a signed integer type. They should not affect your implementation, 
// as the integer's internal binary representation is the same, whether it is signed or unsigned.
// In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, 
// the input represents the signed integer -3 and the output represents the signed integer -1073741825.

// Example 1:
// Input: n = 00000010100101000001111010011100
// Output:    964176192 (00111001011110000010100101000000)
// Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, 
// so return 964176192 which its binary representation is 00111001011110000010100101000000.

// Example 2:
// Input: n = 11111111111111111111111111111101
// Output:   3221225471 (10111111111111111111111111111111)
// Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, 
// so return 3221225471 which its binary representation is 10111111111111111111111111111111.


#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Stores the reversed bits of the input number
        uint32_t rev = 0;
        for (int i = 0; i < 32; i++) {
            rev = (rev << 1) | (n & 1);
            (n) >>= 1;
        }
        return rev;
    }
};

int main() {
    Solution sol;  // Create an instance of the Solution class

    uint32_t n = 10; // Example input (00000010100101000001111010011100 in binary)

    for (int i = 31; i >= 0; i--) {
        if (n & (1 << i)) {
            cout << "1 ";
        }else {
            cout << "0 ";
        }
    }

    cout << endl;

    uint32_t reversed = sol.reverseBits(n); // Call the function

    for (int i = 31; i >= 0; i--) {
        if (reversed & (1 << i)) {
            cout << "1 ";
        }else {
            cout << "0 ";
        }
    }

    cout << "Reversed Bits: " << reversed << endl; // Print result

    return 0;
}
