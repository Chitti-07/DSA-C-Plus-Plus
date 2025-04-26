// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int lastS = 1, lastSS = 1;
        for (int i = n - 2; i >= 0; i--) {
            int temp = lastS;
            lastS = lastS + lastSS;
            lastSS = temp;
        }
        return lastS;
    }
};


int main() {
    Solution sol;
    int n = 6;

    int ways = sol.climbStairs(n);

    cout << "Number of ways to climb " << n << " stairs: " << ways << endl;

    return 0;
}

