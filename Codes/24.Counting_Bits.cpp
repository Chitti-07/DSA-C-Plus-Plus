// Given an integer n, return an array ans of length n + 1 such that 
// for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

// Example 1:
// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10

// Example 2:
// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101

// Follow up:
// It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
// Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    
    int SetBits(int n) {
        int c = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                c++;
            }
        }
        return c;
    }

    
    vector<int> countBits(int n) {
        // Brute Force
        vector<int> bits(n+1, 0);
        // for (int i = 0; i <= n; i++) {
        //     int count = SetBits(i);
        //     bits.push_back(count);
        // }
        // return bits;

        // By using x = x/2 + x%2 we can get how many set bits can a number have, we are saving the already calculated value(Memoziation)
        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i/2] + i%2;
        }
        return bits;
    }


};

int main() {
    Solution solution;
    
    int n = 5; // Example input
    vector<int> result = solution.countBits(n);

    cout << "Count of set bits for numbers from 0 to " << n << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
