#include <iostream>
#include <vector>
using namespace std;

//[3, 6, 3, 89, 5, 2, 6, 9, 0, 7]

class Solution{
public:
    int LongestSubArraySum(vector<int> &arr, int k) {
        int MaxSum = -11111;
        int CurrSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            CurrSum += arr[i];
            if (i >= k -1) {
                MaxSum = max(MaxSum, CurrSum);
                CurrSum -= arr[i - (k - 1)];
            }
        }
        return MaxSum;
    }
};


int main () {
    Solution obj;
    vector<int> arr = {2, 3, 4, 6, 8, 4, 6, 7, 1};
    cout << obj.LongestSubArraySum(arr, 2);
}